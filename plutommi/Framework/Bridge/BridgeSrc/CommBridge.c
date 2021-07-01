

#include "CommBridge.h"
#include "CommBridgeInternal.h"

#ifdef __LOW_LEVEL_BRIDGE_SUPPORT__

#include "Soc_defs.h"
#include "Soc_timer.h"
#include "Soc_enum.h"
#include "Mmi_frm_mem_gprot.h"
#include "Kal_public_api.h"
#include "Dcl.h"
#include "Kal_general_types.h"

#include "Drv_comm.h"

#define MAXPIPENUM 30
#define INVALIDATEINDEX 0xffff
#define IOT_FALSE 0
#define IOT_TRUE 1
#define SOC_MAX_SEND_LEN 1024
#define UART_TO_SOCKET_LEN (1024 * 40)
#define INVALIDATE_SOCKET_ID 0xff
#define DataManagementSize 61


static BridgeItem g_brideg_table[MAXPIPENUM];

static DCL_HANDLE g_handle[uart_max_port + 2];


#define _GET_PIPE_TYPE(PEERINDEX) (((unsigned int)PEERINDEX)>>24)
#define _GET_PIPE_DETAILPORT(PEERINDEX) (((unsigned int)PEERINDEX)&0x00ffffff)

/* UART API */
static int openUartFirstStep(unsigned short port, module_type ownerid);
static void setUartDBConfig(int bandRate, unsigned char port, int flowControl);
static int openUart(UartInfo *uartInfo);
static kal_uint16 writeUartByByte(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
static kal_uint16 getUartRecvBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
static void closeUart(UART_PORT port, module_type ownerid);


/* Socket API */
static kal_uint16 setBridgeConnectFd(kal_int8 socket_id);
#define IOT_BRIDGE_TIMER_VAL    (KAL_TICKS_1_SEC)
#define iot_bridge_start_timer(timer_id, socket_ptr)  soc_start_timer(timer_id, socket_ptr, 0, kal_milli_secs_to_ticks(100));

/* USB API */
static int openUsbPort(UsbInfo *usbInfo);
static void closeUsb(kal_uint32 port, module_type ownerid);


/* Bridge API */
static void insertBridgeInfo(BridgeTableElement *bridgeItem, mbuf *head_ptr, int sendDataLen);
static int getPipeID(BridgePeerInfo *res);
static int getFirstCanUseBridgeIndex(int firPeerIndex, int secPeerIndex);
static int insertPipeTable(int res, int des);
static void freeBridgeItemNode(BridgeTableElement *tableBridgeElement, int peerType);
static void sendLeftDataByBridgeInternal(bridge_node_struct_ptr peer_node_ptr);
static void initBridgeItemInternal(bridge_node_struct_ptr bridge_node_ptr, int peerNodeType);
static void processPortDataHandlerInternal(int actSelfVal);
static kal_int32 sendPortDataByBridge(bridge_node_struct_ptr bridge_node_ptr);
static void sendLeftPortDataByBridgeInternal(int selfIndex);
static int recvDataFromPortByBridge(int actSelfVal, bridge_node_struct_ptr bridge_info_ptr);
static void destroyBridgeItem(int index);


/* Tarce */
extern void kal_prompt_trace(module_type mod_id, const kal_char *fmt,...);


#define BRIDGE_DATA_CHECK
#ifdef BRIDGE_DATA_CHECK
kal_int32 g_dcl_to_wifi_total_len = 0;
kal_int32 g_dcl_to_wifi_send_len = 0;
kal_int32 g_wifi_to_dcl_total_len = 0;
kal_int32 g_wifi_to_dcl_send_len = 0;
#endif /* BRIDGE_DATA_CHECK */


#define BRIDGE_DATA_CHECK_PORT_TO_SOCKET
#ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
kal_uint32 g_trace_index = 0;
kal_uint32 g_work_item = 0;
kal_uint32 g_work_status[6];
#endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */

/*
kal_uint32 g_total_read_time = 0;
kal_uint32 g_total_write_time = 0;
kal_uint32 g_total_left_len = 0;
*/

/* memory */
extern void free_soc_mem(struct mbuf *buf_data, kal_int32 keep);
#define iot_bridge_soc_free_mem(buf_data_ptr)   free_soc_mem(buf_data_ptr, 0);
#define iot_bridge_alloc_mem(size)  mmi_frm_asm_alloc_anonymous(size);
#define iot_bridge_free_mem(buff_ptr)   mmi_frm_asm_free_anonymous(buff_ptr);
static void initBridgeTransferData(BridgeTableElement *bridgeItemPtr);
static DataManagement* allocate_bridge_node_data(BridgeTableElement *bridgeItemPtr);
static void release_bridge_node_data(BridgeTableElement *bridgeItemPtr);


/*****************************************************************************
* FUNCTION
*  initBridgeTransferData
* DESCRIPTION
*  initBridgeTransferData
*  for app use
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void initBridgeTransferData(BridgeTableElement *bridgeItemPtr)
{
     bridgeItemPtr->firstPeerDataPtr = iot_bridge_alloc_mem(UART_TO_SOCKET_LEN);
     bridgeItemPtr->lastPeerDataPtr = bridgeItemPtr->firstPeerDataPtr;
     bridgeItemPtr->bridgeDataHeadPtr = bridgeItemPtr->firstPeerDataPtr;
     set_soc_recv_empty_flag(bridgeItemPtr->reserved);
     clear_soc_recv_full_flag(bridgeItemPtr->reserved);
}


/*****************************************************************************
* FUNCTION
*  initBridgeTransferNodeData
* DESCRIPTION
*  initBridgeTransferNodeData
*  for app use
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void initBridgeTransferNodeData(BridgeTableElement *bridgeItemPtr)
{
    int index = 0;
    DataManagement *tmp_ptr = NULL;
    tmp_ptr = (DataManagement*)iot_bridge_alloc_mem(sizeof(DataManagement) * DataManagementSize);
        
    bridgeItemPtr->bridgeDataHeadPtr = (kal_uint8*)tmp_ptr;
    bridgeItemPtr->firstPeerDataPtr = NULL;
    bridgeItemPtr->lastPeerDataPtr = (kal_uint8*)tmp_ptr;

    for(index = 0; index < DataManagementSize; index++)
    {
        tmp_ptr->next = tmp_ptr + 1;
        ++tmp_ptr;
    }
    (tmp_ptr - 1)->next = (DataManagement*)bridgeItemPtr->bridgeDataHeadPtr;
}


/*****************************************************************************
* FUNCTION
*  allocate_bridge_node_data
* DESCRIPTION
*  allocate_bridge_node_data
*  for app use
* PARAMETERS
*  
* RETURNS
*  DataManagement*
*****************************************************************************/
static DataManagement* allocate_bridge_node_data(BridgeTableElement *bridgeItemPtr)
{
    DataManagement* data_ptr = NULL;
    // bridge node empty
    if(NULL == bridgeItemPtr->firstPeerDataPtr)
    {
        BRIDGE_TRACE(APP_BRIDGE_ALLOCATE_HEADER, bridgeItemPtr->firstPeerDataPtr);
        bridgeItemPtr->firstPeerDataPtr = bridgeItemPtr->bridgeDataHeadPtr;
        bridgeItemPtr->lastPeerDataPtr = bridgeItemPtr->bridgeDataHeadPtr;
    }
    else if( (kal_uint8*)(((DataManagement*)(bridgeItemPtr->lastPeerDataPtr))->next) == bridgeItemPtr->firstPeerDataPtr)
    {
        /* bridge node full */
        BRIDGE_TRACE(APP_BRIDGE_ALLOCATE_BUFFER_FULL);
        ASSERT(1 == 0);        
        return data_ptr;
    }

    data_ptr = (DataManagement*)bridgeItemPtr->lastPeerDataPtr;

    ASSERT(NULL == data_ptr->headPtr);
    
    BRIDGE_TRACE(APP_BRIDGE_ALLOCATE_BUFFER_NEXT, bridgeItemPtr->lastPeerDataPtr);
    bridgeItemPtr->lastPeerDataPtr = (kal_uint8*)data_ptr->next;
    return data_ptr;
}


/*****************************************************************************
* FUNCTION
*  release_bridge_node_data
* DESCRIPTION
*  release_bridge_node_data
*  for app use
* PARAMETERS
*  
* RETURNS
*  BridgeTableElement *bridgeItemPtr
*****************************************************************************/
static void release_bridge_node_data(BridgeTableElement *bridgeItemPtr)
{
    DataManagement* data_ptr = NULL;

    ASSERT(bridgeItemPtr->firstPeerDataPtr != bridgeItemPtr->lastPeerDataPtr);

    ((DataManagement *)(bridgeItemPtr->firstPeerDataPtr))->headPtr = NULL;
    bridgeItemPtr->firstPeerDataPtr = (kal_uint8*)(((DataManagement *)(bridgeItemPtr->firstPeerDataPtr))->next);
    BRIDGE_TRACE(APP_BRIDGE_RELEASE_BUFFER, bridgeItemPtr->firstPeerDataPtr);

    if(bridgeItemPtr->firstPeerDataPtr == bridgeItemPtr->lastPeerDataPtr)
    {
        //free last data in queue
        bridgeItemPtr->lastPeerDataPtr = bridgeItemPtr->bridgeDataHeadPtr;
        bridgeItemPtr->firstPeerDataPtr = NULL;
        BRIDGE_TRACE(APP_BRIDGE_RELEASE_EMPTY);
    }
}



/*****************************************************************************
* FUNCTION
*  openUartFirstStep
* DESCRIPTION
*  openUartFirstStep
*  for app use
* PARAMETERS
*  int port, module_type ownerid
* RETURNS
*  void
*****************************************************************************/
static int openUartFirstStep(unsigned short port, module_type ownerid)
{	
    UART_CTRL_OPEN_T data;
	DCL_STATUS status;
    kal_uint8 sleep_handle;

	data.u4OwenrId = ownerid;
    if(NULL != g_handle[port])
    {
        BRIDGE_TRACE(APP_BRIDGE_OPEN_UART,port);
    }
	g_handle[port] = DclSerialPort_Open(port,0);
   	status = DclSerialPort_Control(g_handle[port],SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
	if(STATUS_OK != status)
	{
        BRIDGE_TRACE(APP_BRIDGE_OPEN_FAIL_UART, status);
		return IOT_FALSE;
	}

    sleep_handle = L1SM_GetHandle(); 
	L1SM_SleepDisable(sleep_handle);

    BRIDGE_TRACE(APP_BRIDGE_OPEN_SUCCESS_FIRST_STEP_UART);
    
	return IOT_TRUE;	
}

/*****************************************************************************
* FUNCTION
*  setUartDBConfig
* DESCRIPTION
*  setUartDBConfig
*  for app use
* PARAMETERS
*  int bandRate, MMI_BOOL flowControl
* RETURNS
*  void
*****************************************************************************/
static void setUartDBConfig(int bandRate, unsigned char port, int flowControl)
{
    UART_CTRL_DCB_T data;

    data.u4OwenrId = MOD_SOC;
    
    data.rUARTConfig.u4Baud = bandRate;
	data.rUARTConfig.u1DataBits = len_8;
	data.rUARTConfig.u1StopBits = sb_1;
	data.rUARTConfig.u1Parity = pa_none;
	data.rUARTConfig.u1FlowControl = flowControl;
	data.rUARTConfig.ucXonChar = 0x11;
	data.rUARTConfig.ucXoffChar = 0x13;
	data.rUARTConfig.fgDSRCheck = (unsigned char)IOT_FALSE;    

	DclSerialPort_Control(g_handle[port],SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
}


/*****************************************************************************
* FUNCTION
*  OpenUart
* DESCRIPTION
*  OpenUart
*  
* PARAMETERS
*  UartInfo *uartInfo
* RETURNS
*  void
*****************************************************************************/
static int openUart(UartInfo *uartInfo)
{
    int status = 0;
    
    BRIDGE_TRACE(APP_BRIDGE_OPEN_DETAIL_UART, uartInfo->uart_port, uartInfo->uart_band);

    status = openUartFirstStep(uartInfo->uart_port,  MOD_SOC);
    
    if(IOT_TRUE == status)
	{	    
		setUartDBConfig(uartInfo->uart_band, uartInfo->uart_port, uartInfo->flowControl);
	}
    else
    {
        return IOT_FALSE;
    }

    BRIDGE_TRACE(APP_BRIDGE_OPEN_SUCCESS_UART);
    
    return IOT_TRUE;
}


/*****************************************************************************
* FUNCTION
*  closeUart
* DESCRIPTION
*  closeUart
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void closeUart(UART_PORT port, module_type ownerid)
{
	UART_CTRL_CLOSE_T data;
	data.u4OwenrId = ownerid;
	DclSerialPort_Control(g_handle[port], SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
    g_handle[port] = NULL;
}



/*****************************************************************************
* FUNCTION
*  writeUartByByte
* DESCRIPTION
*  writeUartByByte
*  
* PARAMETERS
*  UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid
* RETURNS
*  void
*****************************************************************************/
static kal_uint16 writeUartByByte(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
	UART_CTRL_PUT_BYTES_T data;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;
	DclSerialPort_Control(g_handle[port],SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	return data.u2RetSize;
}

kal_uint16 getUartRecvBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
	UART_CTRL_GET_BYTES_T data;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;
	data.pustatus = status;

	DclSerialPort_Control(g_handle[port],SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	return data.u2RetSize;
}


/*****************************************************************************
* FUNCTION
*  setConnectSocketFd
* DESCRIPTION
*  setConnectSocketFd
*  for app use
* PARAMETERS
*  kal_int8 socket_id, kal_uint32 option
* RETURNS
*  kal_unit16
*****************************************************************************/
static kal_uint16 setConnectSocketFd(kal_int8 socket_id, kal_uint32 option)
{
    kal_uint8 status;
    kal_int8 soc_return;

    soc_return = soc_getsockopt(socket_id,
                            	option, 
                            	&status, sizeof(status));
    BRIDGE_TRACE(APP_BRIDGE_GET_SOCKET_PROPERITIES, option, soc_return);
    if(SOC_SUCCESS != soc_return)
    {
        soc_return = soc_setsockopt(socket_id,
                            		option, 
                            		&status, sizeof(status)); // set nonblock
        if (SOC_SUCCESS != soc_return)
    	{
    		//soc_close(socket_id);
    		BRIDGE_TRACE(APP_BRIDGE_SET_SOCKET_PROPERITIES, option, soc_return);
            return IOT_FALSE;
    	}
     }

    return IOT_TRUE;
}


/*****************************************************************************
* FUNCTION
*  setBridgeConnectFd
* DESCRIPTION
*  setBridgeConnectFd
*  for app use
* PARAMETERS
*  kal_int8 socket_id
* RETURNS
*  kal_unit16
*****************************************************************************/
static kal_uint16 setBridgeConnectFd(kal_int8 socket_id)
{
    kal_uint16 soc_return;
    
    soc_return = setConnectSocketFd(socket_id, SOC_NBIO);
    if(IOT_FALSE == soc_return)
    {
        return IOT_FALSE;
    }
    
    soc_return = setConnectSocketFd(socket_id, SOC_ASYNC);
    return soc_return;
}


/*****************************************************************************
* FUNCTION
*  openUsbPort
* DESCRIPTION
*  OpenUart
*  
* PARAMETERS
*  UsbInfo *usbInfo
* RETURNS
*  void
*****************************************************************************/
static int openUsbPort(UsbInfo *usbInfo)
{
    int status = 0;
    
    BRIDGE_TRACE(APP_BRIDGE_OPEN_USB_PORT, usbInfo->usb_port);

    status = openUartFirstStep(usbInfo->usb_port,  MOD_SOC);    
    
    return status;
}


/*****************************************************************************
* FUNCTION
*  closeUsb
* DESCRIPTION
*  closeUsb
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void closeUsb(kal_uint32 port, module_type ownerid)
{
    UART_CTRL_CLOSE_T data;
	data.u4OwenrId = ownerid;
	DclSerialPort_Control(g_handle[port], SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
    g_handle[port] = NULL;
}




/*****************************************************************************
* FUNCTION
*  initEachPeerInfo
* DESCRIPTION
*  createBridge
*  for app use
* PARAMETERS
*  BridgePeerInfo *bridgePeerInfo
* RETURNS
*  int
*****************************************************************************/
int initEachPeerInfo(BridgePeerInfo *bridgePeerInfo)
{
    UartInfo *tmpUartInfo = NULL;
    kal_uint8 sockFd = INVALIDATE_SOCKET_ID;
    UsbInfo *tmpUsbInfo = NULL;

    if(UART_PIPE_TYPE == bridgePeerInfo->type)
    {
        tmpUartInfo = &(bridgePeerInfo->TypeInfo.uartInfo);
    }
    else if(SOCKET_PIPE_TYPE == bridgePeerInfo->type)
    {
        sockFd = bridgePeerInfo->TypeInfo.socketInfo.socket_accpet_fd;
    }
    else if(USB_PIPE_TYPE == bridgePeerInfo->type)
    {
        tmpUsbInfo = &(bridgePeerInfo->TypeInfo.usbInfo);
    }
    
    if( NULL != tmpUartInfo )
    {
	    if(IOT_FALSE == openUart(tmpUartInfo))
        {
            return IOT_FALSE;
        }
    }
    else if(INVALIDATE_SOCKET_ID != sockFd)
    {
        BRIDGE_TRACE(APP_BRIDGE_SOCKET_INIT, sockFd);
        if(IOT_FALSE == setBridgeConnectFd(sockFd))
        {
            return IOT_FALSE;
        }
    }
    else if( NULL != tmpUsbInfo )
    {
        if(IOT_FALSE == openUsbPort(tmpUsbInfo))
        {
            return IOT_FALSE;
        }
    }

    return IOT_TRUE;
}


/*****************************************************************************
* FUNCTION
*  createBridge
* DESCRIPTION
*  createBridge
*  for app use
* PARAMETERS
*  BridgeInfo *res, BridgeInfo *des
* RETURNS
*  void
*****************************************************************************/
int createBridge(BridgePeerInfo *firstPeerInfo, BridgePeerInfo *secondPeerInfo)
{
    int ret = IOT_TRUE;
    int index = INVALIDATEINDEX;
    
    index= insertPipeTable(getPipeID(firstPeerInfo), getPipeID(secondPeerInfo));

    if(INVALIDATEINDEX != index)
    {
        ret = initEachPeerInfo(firstPeerInfo);
        if(IOT_FALSE == ret)
        {
            BRIDGE_TRACE(APP_BRIDGE_CREATE_FAIL);
            closeBridge(getPipeID(firstPeerInfo));
            return IOT_FALSE;
        }

        set_bridge_validate_flag(g_brideg_table[index].firstBridgeItem.reserved);
        
        ret = initEachPeerInfo(secondPeerInfo);
        if(IOT_FALSE == ret)
        {
            BRIDGE_TRACE(APP_BRIDGE_CREATE_FAIL);
            closeBridge(getPipeID(secondPeerInfo));
            return IOT_FALSE;
        }

        set_bridge_validate_flag(g_brideg_table[index].secondBridgeItem.reserved);
    }
    else
    {
        BRIDGE_TRACE(APP_BRIDGE_CREATE_INSERT_ITEM_FAIL);
        ret = IOT_FALSE;
    }
    
    BRIDGE_TRACE(APP_BRIDGE_CREATE);
    
    return ret;    
}


/*****************************************************************************
* FUNCTION
*  closeBridgeEx
* DESCRIPTION
*  closeBridgeEx
*  for app use
* PARAMETERS
*  BridgeInfo *res, BridgeInfo *des
* RETURNS
*  void
*****************************************************************************/
int closeBridgeEx(BridgePeerInfo *firstPeerInfo, BridgePeerInfo *secondPeerInfo)
{
    int searchIndex = searchBridgeIndex(getPipeID(firstPeerInfo), getPipeID(secondPeerInfo));

    if(searchIndex == INVALIDATEINDEX)
    {
        BRIDGE_TRACE(APP_BRIDGE_USER_CLOSE_BRIDGE_INVALIDATE);
        return IOT_FALSE;
    }
    else
    {
        destroyBridgeItem(searchIndex);
        BRIDGE_TRACE(APP_BRIDGE_USER_CLOSE_BRIDGE_SUCCESS);
        return IOT_TRUE;
    }
}

/*****************************************************************************
* FUNCTION
*  searchSelfInBridge
* DESCRIPTION
*  searchSelfInBridge
*  for app use
* PARAMETERS
*  BridgeInfo *res
* RETURNS
*  void
*****************************************************************************/
bridge_node_struct_ptr searchSelfInBridge(int peerIndex)
{
    int tableIndex = 0;
    for(tableIndex = 0; tableIndex < MAXPIPENUM; ++tableIndex)
    {
        if(peerIndex == g_brideg_table[tableIndex].firstBridgeItem.peerIndex)
        {
            BRIDGE_TRACE(APP_BRIDGE_SEARCH, tableIndex);
            
            return &(g_brideg_table[tableIndex].firstBridgeItem);
        }
        else if(peerIndex == g_brideg_table[tableIndex].secondBridgeItem.peerIndex)
        {
            BRIDGE_TRACE(APP_BRIDGE_SEARCH, tableIndex);
            
            return &(g_brideg_table[tableIndex].secondBridgeItem);
        }
     }

    BRIDGE_TRACE(APP_BRIDGE_SEARCH_FAIL);
          
    return NULL;
}


/*****************************************************************************
* FUNCTION
*  searchPeerInBridge
* DESCRIPTION
*  createBridge
*  for app use
* PARAMETERS
*  BridgeInfo *res
* RETURNS
*  void
*****************************************************************************/
bridge_node_struct_ptr searchPeerInBridge(int peerIndex)
{
    int tableIndex = 0;
    for(tableIndex = 0; tableIndex < MAXPIPENUM; ++tableIndex)
    {
        if(peerIndex == g_brideg_table[tableIndex].firstBridgeItem.peerIndex)
        {
            return &(g_brideg_table[tableIndex].secondBridgeItem);
        }
        else if(peerIndex == g_brideg_table[tableIndex].secondBridgeItem.peerIndex)
        {
            return &(g_brideg_table[tableIndex].firstBridgeItem);
        }
     }

    return NULL;
}


static void insertBridgeInfo(BridgeTableElement *bridgeItem, mbuf *head_ptr, int sendDataLen)
{   
    DataManagement *dataFLCPtr;
    int nodeCount = 0;
    int leftDataLen = 0;

    dataFLCPtr = allocate_bridge_node_data(bridgeItem);

    BRIDGE_TRACE(APP_BRIDGE_ALLOCATE_DATA, dataFLCPtr);

    if(NULL != dataFLCPtr)
    {
        dataFLCPtr->headPtr = head_ptr;
        dataFLCPtr->dataPtr = head_ptr->m_data;
        dataFLCPtr->sendDataLen = sendDataLen;
        dataFLCPtr->totalDataLen = head_ptr->m_len;
    }

#ifdef BRIDGE_DATA_CHECK
    /*
    dataFLCPtr = (DataManagement *)bridgeItem->firstPeerDataPtr;
    if(NULL != dataFLCPtr)
    {
        while(dataFLCPtr !=  (DataManagement *)bridgeItem->lastPeerDataPtr)
        {
            ++nodeCount;
            leftDataLen += (dataFLCPtr->totalDataLen - dataFLCPtr->sendDataLen);
            dataFLCPtr = dataFLCPtr->next;
        }
        ++nodeCount;
        leftDataLen += (dataFLCPtr->totalDataLen - dataFLCPtr->sendDataLen);
        BRIDGE_SEND_TRACE(APP_BRIDGE_ALLOCATE_CALC, g_wifi_to_dcl_total_len, g_wifi_to_dcl_send_len, nodeCount, leftDataLen);
    }
    */
#endif /* BRIDGE_DATA_CHECK */
}


/*****************************************************************************
* FUNCTION
*  isUSBPort
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
kal_uint32 isUSBPort(kal_uint8 port)
{
    if( (uart_port_usb <= port) && (uart_port_usb3 >= port) )
    {
        return IOT_TRUE;
    }
    else
    {
        return IOT_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  sendDataFromPortByBridge
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void processPortDataHandler(kal_uint16 port)
{
    if(IOT_TRUE == isUSBPort(port))
    {
        processPortDataHandlerInternal(_PIPE_ID(USB_PIPE_TYPE, port));
    }
    else
    {
        processPortDataHandlerInternal(_PIPE_ID(UART_PIPE_TYPE, port));
    }
}


/*****************************************************************************
* FUNCTION
*  sendLeftPortDataByBridge
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void sendLeftPortDataByBridge(kal_uint16 port)
{
     if(IOT_TRUE == isUSBPort(port))
    {
        sendLeftPortDataByBridgeInternal(_PIPE_ID(USB_PIPE_TYPE, port));
    }
    else
    {
        sendLeftPortDataByBridgeInternal(_PIPE_ID(UART_PIPE_TYPE, port));
    }
}



/*****************************************************************************
* FUNCTION
*  recvDataFromPortByBridge
* DESCRIPTION
*  used for uart => socket, first time socket recv buffer data send to uart
* PARAMETERS
*  bridge_node_struct_ptr bridge_node_ptr  for uart struct use
*  void *data_ptr, int length send data length and data
* RETURNS
*  void
*****************************************************************************/
void processPortDataHandlerInternal(int actSelfVal)
{
    int actSelfType = _GET_PIPE_TYPE(actSelfVal);
    int actSelfPort = _GET_PIPE_DETAILPORT(actSelfVal);
    kal_int32 recv_len = 0;
    kal_int32 send_len = 0;
    bridge_node_struct_ptr bridge_info_ptr = NULL;

    // peer should be socket now

    bridge_info_ptr = searchPeerInBridge(actSelfVal);

    ASSERT(SOCKET_PIPE_TYPE == _GET_PIPE_TYPE(bridge_info_ptr->peerIndex));
    
    // should set force_recv_flag when there is no space to recv data from port     
    set_soc_need_force_recv_flag(bridge_info_ptr->reserved);

    #ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
    g_trace_index++;
    g_work_item = 0;
    g_work_status[g_work_item] = g_trace_index;
    #endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
    
    while(1)
    {        
        recv_len = recvDataFromPortByBridge(actSelfPort, bridge_info_ptr);       
        
        send_len = sendPortDataByBridge(bridge_info_ptr);

        if( (0 >= recv_len) && (0 >= send_len) )
        {           
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  recvDataFromPortByBridge
* DESCRIPTION
*  
* PARAMETERS
*  actSelfVal: port
*  bridge_info_ptr: store data location
* RETURNS
*  void
*****************************************************************************/
kal_int32 recvDataFromPortByBridge(int actSelfVal, bridge_node_struct_ptr bridge_info_ptr)
{
    int actSelfType = _GET_PIPE_TYPE(actSelfVal);
    int actSelfPort = _GET_PIPE_DETAILPORT(actSelfVal);
    kal_int32 uart_real_len = 0;
    kal_uint8 status;
    kal_int32 left_space_len= 0;
    kal_int32 forward_left_len = 0;
    kal_int32 backward_left_len = 0;
    kal_int32 need_cnt_recv_len = 0;
    kal_int32 recv_total_len = 0;
    kal_uint32 time;

    // peer should be socket now
    BRIDGE_TRACE(APP_BRIDGE_FROM_UART, actSelfType);    
    
    if( 0 != get_soc_recv_full_flag(bridge_info_ptr->reserved))        
    {
    #ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
        g_work_status[g_work_item + 1] = __LINE__;
    #endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
        return 0;
    }
    if(0 == get_soc_need_force_recv_flag(bridge_info_ptr->reserved))
    {
    #ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
        g_work_status[g_work_item + 1] = __LINE__;
    #endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
        return 0;
    }

    #if 1
    //time = drv_get_current_time();
    #endif
    
    if(bridge_info_ptr->lastPeerDataPtr >= bridge_info_ptr->firstPeerDataPtr)
    {
        need_cnt_recv_len = UART_TO_SOCKET_LEN - ( bridge_info_ptr->lastPeerDataPtr - bridge_info_ptr->bridgeDataHeadPtr );
        //g_total_left_len = bridge_info_ptr->lastPeerDataPtr - bridge_info_ptr->bridgeDataHeadPtr;
    }
    else
    {
        need_cnt_recv_len = bridge_info_ptr->firstPeerDataPtr - bridge_info_ptr->lastPeerDataPtr;
        //g_total_left_len = UART_TO_SOCKET_LEN - ( bridge_info_ptr->firstPeerDataPtr - bridge_info_ptr->lastPeerDataPtr );
    }
    
    
    uart_real_len = getUartRecvBytes(actSelfPort, bridge_info_ptr->lastPeerDataPtr, 
                                                  need_cnt_recv_len, &status, MOD_SOC); 

    
    if(uart_real_len < need_cnt_recv_len)
    {
        // port cahce cleared
        clear_soc_need_force_recv_flag(bridge_info_ptr->reserved);
    }

#ifdef BRIDGE_DATA_CHECK
    g_dcl_to_wifi_total_len += uart_real_len;
    BRIDGE_SEND_TRACE(APP_BRIDGE_RECV_DCL_DATA_INTERNAL, g_dcl_to_wifi_total_len, uart_real_len, need_cnt_recv_len);
#endif

    /*
    memset(bridge_info_ptr->bridgeDataHeadPtr, 'a', UART_TO_SOCKET_LEN);
    bridge_info_ptr->lastPeerDataPtr = bridge_info_ptr->bridgeDataHeadPtr;
    bridge_info_ptr->firstPeerDataPtr = bridge_info_ptr->bridgeDataHeadPtr;
    uart_real_len = UART_TO_SOCKET_LEN;   
    */

    //test
    #if 1
    /*
    if(1 < uart_real_len)
    {
        //*(bridge_info_ptr->lastPeerDataPtr) = 'U';
        //*(bridge_info_ptr->lastPeerDataPtr + uart_real_len - 1) = 'E';
        if(36 < uart_real_len)
        {
            g_total_read_time += (drv_get_current_time() - time);
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr)) = g_total_read_time;
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 1) = 't';
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 2) = g_total_write_time;
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 3) = 't';
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 4) = uart_real_len;
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 5) = 't';
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 6) = g_total_left_len;
            *((kal_uint32*)(bridge_info_ptr->lastPeerDataPtr) + 7) = 't';
            *((bridge_info_ptr->lastPeerDataPtr) + uart_real_len - 2) = '\x0d';
            *((bridge_info_ptr->lastPeerDataPtr) + uart_real_len - 1) = '\x0a';
            
            kal_prompt_trace(MOD_IOT, "uart_real_len :%d",g_total_read_time);
        }
        else
        {
            memset(bridge_info_ptr->lastPeerDataPtr, 'B', uart_real_len);
        }
    }
    */
    #endif


    bridge_info_ptr->lastPeerDataPtr += uart_real_len;

    if( bridge_info_ptr->lastPeerDataPtr == (bridge_info_ptr->bridgeDataHeadPtr + UART_TO_SOCKET_LEN) )
    {
        bridge_info_ptr->lastPeerDataPtr = bridge_info_ptr->bridgeDataHeadPtr;      
    }

    if( 0 < uart_real_len )
    {    
        if( bridge_info_ptr->firstPeerDataPtr == bridge_info_ptr->lastPeerDataPtr)
        {
            //recv buffer full
            set_soc_recv_full_flag(bridge_info_ptr->reserved);
            BRIDGE_TRACE(APP_BRIDGE_DCL_RECV_NODE_BUFFER_FULL);
        }
        clear_soc_recv_empty_flag(bridge_info_ptr->reserved);
    }

#ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET        
    g_work_status[g_work_item + 1] = __LINE__;
#endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */

    return uart_real_len;        
}


/*****************************************************************************
* FUNCTION
*  sendDataFromSocByBridge
* DESCRIPTION
*  used for socket => uart, first time socket recv buffer data send to uart
* PARAMETERS
*  bridge_node_struct_ptr bridge_node_ptr  for uart struct use
*  void *data_ptr, int length send data length and data
* RETURNS
*  void
*****************************************************************************/
void sendDataFromSocByBridge(bridge_node_struct_ptr bridge_node_ptr, mbuf *buf_data)
{
    int actPeerType;
    int actPeerPort;
    DataManagement *dataFLCPtr = (DataManagement*)(bridge_node_ptr->firstPeerDataPtr);    
    int actPeerVal = bridge_node_ptr->peerIndex;
    int sendLen = 0;
    int totalLen = 0;
    kal_uint8 *dataSendPtr = NULL;    
    
    actPeerType = _GET_PIPE_TYPE(actPeerVal); 
    actPeerPort = _GET_PIPE_DETAILPORT(actPeerVal); 
    totalLen = buf_data->m_len;
    dataSendPtr = buf_data->m_data;
    
#ifdef BRIDGE_DATA_CHECK
    g_wifi_to_dcl_total_len += totalLen;    
    BRIDGE_SEND_TRACE(APP_BRIDGE_SEND_UART_DATA, g_wifi_to_dcl_total_len);
#endif /* BRIDGE_DATA_CHECK */
    
     
    //there is no data has left in queue, can send
    if(NULL == dataFLCPtr)
    {
        sendLen = writeUartByByte(actPeerPort, dataSendPtr, totalLen, MOD_SOC);
        
    #ifdef BRIDGE_DATA_CHECK
        g_wifi_to_dcl_send_len += sendLen;
        BRIDGE_SEND_TRACE(APP_BRIDGE_AFTER_SEND_UART_DATA, g_wifi_to_dcl_send_len);
    #endif /* BRIDGE_DATA_CHECK */
        
        BRIDGE_TRACE( APP_BRIDGE_FROM_UART_LOGICAL, sendLen, totalLen, actPeerType);

        if(sendLen != totalLen)
        {
            insertBridgeInfo(bridge_node_ptr, buf_data, sendLen);  
        }
        else
        {
            iot_bridge_soc_free_mem(buf_data);                
        }
    }
    else //should send queue data first
    {            
        BRIDGE_TRACE(APP_BRIDGE_FROM_UART_LOGICAL_LEFT);

        insertBridgeInfo(bridge_node_ptr, buf_data, sendLen); 
        
        sendLeftDataByBridgeInternal(bridge_node_ptr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  check_bridge_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bridge_node_struct_ptr bridge_info_ptr       
 * RETURNS
 *  void
 *****************************************************************************/
void check_bridge_close(bridge_node_struct_ptr bridge_info_ptr)
{
    if( 0 != get_soc_close_flag(bridge_info_ptr->peerIndex) )
    {
        prepare_bridge_close(bridge_info_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  prepare_bridge_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bridge_node_struct_ptr bridge_info_ptr       
 * RETURNS
 *  void
 *****************************************************************************/
void prepare_bridge_close(bridge_node_struct_ptr bridge_info_ptr)
{    
    bridge_node_struct_ptr bridge_peer_ptr = NULL;

    //make port can't recv data IOT outside
    set_soc_block_send_flag(bridge_info_ptr->reserved);        
    set_soc_recv_full_flag(bridge_info_ptr->reserved);
    clear_soc_need_force_recv_flag(bridge_info_ptr->reserved);
    set_soc_recv_empty_flag(bridge_info_ptr->reserved);
    
    bridge_peer_ptr = searchPeerInBridge(bridge_info_ptr->peerIndex);
    // no left data need usb/uart to send to destination
    if(NULL == bridge_peer_ptr->firstPeerDataPtr)
    {
        BRIDGE_TRACE(APP_BRIDGE_CLOSE_TIMER);
        // send msg to close bridge because LOCK
        iot_bridge_start_timer(SOC_BRIDGE_TIMER, (kal_uint32)bridge_info_ptr);        
    }
}


/*****************************************************************************
* FUNCTION
*  sendPortDataByBridge
* DESCRIPTION
*  used for uart => socket, first time socket recv buffer data send to uart
* PARAMETERS
*  bridge_node_struct_ptr bridge_node_ptr  for uart struct use
*  void *data_ptr, int length send data length and data
* RETURNS
*  void
*****************************************************************************/
static kal_int32 sendPortDataByBridge(bridge_node_struct_ptr bridge_node_ptr)
{    
    kal_uint8 *dataQueueEndPtr = bridge_node_ptr->bridgeDataHeadPtr + UART_TO_SOCKET_LEN;
    kal_uint8 *dataBeginPtr = bridge_node_ptr->firstPeerDataPtr;
    kal_uint8 *dataEndPtr = bridge_node_ptr->lastPeerDataPtr;
    kal_int32 need_send_len = 0;
    kal_int32 real_send_len = 0;
    kal_int32 step_send_len = 0;
    kal_int32 actPeerVal = bridge_node_ptr->peerIndex;
    kal_int32 actPeerPort = _GET_PIPE_DETAILPORT(actPeerVal);
    kal_int32 ret_send_val = 0;
    kal_uint32 time = 0;

    if(0 != get_soc_block_send_flag(bridge_node_ptr->reserved))
    {
#ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
        g_work_status[g_work_item + 2] = __LINE__;
#endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
        return 0;
    }

    if(0 != get_soc_recv_empty_flag(bridge_node_ptr->reserved))
    {
#ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
        g_work_status[g_work_item + 2] = __LINE__;
#endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
        return 0;
    }

    //time = drv_get_current_time();
    
    if(dataBeginPtr < dataEndPtr)
    {
        need_send_len = bridge_node_ptr->lastPeerDataPtr - bridge_node_ptr->firstPeerDataPtr;
    }
    else
    {
        need_send_len = dataQueueEndPtr - bridge_node_ptr->firstPeerDataPtr;
    }
        
    while( real_send_len < need_send_len )
    {
        step_send_len = need_send_len - real_send_len;
        
        if(SOC_MAX_SEND_LEN < step_send_len )
        {
            step_send_len = SOC_MAX_SEND_LEN;            
        }         

        ret_send_val = soc_send(actPeerPort, bridge_node_ptr->firstPeerDataPtr + real_send_len, step_send_len, 0);
        if( 0 <= ret_send_val )
        {
            real_send_len += ret_send_val;
        #ifdef BRIDGE_DATA_CHECK
            g_dcl_to_wifi_send_len += ret_send_val;
            BRIDGE_SEND_TRACE(APP_BRIDGE_SEND_DCL_DATA, real_send_len, g_dcl_to_wifi_send_len);
        #endif /* BRIDGE_DATA_CHECK */
        }
        else if(SOC_WOULDBLOCK == ret_send_val)        
        {
            //start timer
            if( (0 == get_soc_block_send_flag(bridge_node_ptr->reserved))
                && (0 == get_soc_close_flag(bridge_node_ptr->reserved)) )
            {   
                BRIDGE_TRACE(APP_BRIDGE_START_TIMER);
                iot_bridge_start_timer(SOC_BRIDGE_TIMER, (kal_uint32)bridge_node_ptr);               
            }
            set_soc_block_send_flag(bridge_node_ptr->reserved);            
        #ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
            g_work_status[g_work_item + 2] = __LINE__;
        #endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
            break;
        }
        else
        {
            // SOC_PIPE ......
            // notify peer bridge item to closing bridge after left data has completed send
            BRIDGE_TRACE(APP_BRIDGE_SEND_TO_SOC_FAIL);
            set_soc_close_flag(bridge_node_ptr->reserved);
            prepare_bridge_close(bridge_node_ptr);
        #ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
            g_work_status[g_work_item + 2] = __LINE__;
        #endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */
            return 0;
        }
    } 

#ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
    if(real_send_len == need_send_len)
    {
        g_work_status[g_work_item + 2] = __LINE__;
    }
    /*
    if(0 < real_send_len)
    {
        memset(bridge_node_ptr->firstPeerDataPtr, 'A', real_send_len);
    }
    */
#endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */

    #if 1
    //g_total_write_time += (drv_get_current_time() - time);
    #endif
        
    bridge_node_ptr->firstPeerDataPtr += real_send_len;    

    if(bridge_node_ptr->firstPeerDataPtr == dataQueueEndPtr)
    {
        bridge_node_ptr->firstPeerDataPtr =  bridge_node_ptr->bridgeDataHeadPtr;
    }

    if(0 < real_send_len)
    {
        clear_soc_recv_full_flag(bridge_node_ptr->reserved);
        if(bridge_node_ptr->firstPeerDataPtr == bridge_node_ptr->lastPeerDataPtr)
        {
            set_soc_recv_empty_flag(bridge_node_ptr->reserved);
        }
    }


    return real_send_len;
}


/*****************************************************************************
* FUNCTION
*  recvDataFromPortByBridge
* DESCRIPTION
*  
* PARAMETERS
*  actSelfVal: port
*  bridge_info_ptr: store data location
* RETURNS
*  void
*****************************************************************************/
kal_int32 sendDataFromPortByTimer(bridge_node_struct_ptr bridge_info_ptr)
{
    int actSelfVal = bridge_info_ptr->peerIndex;
    int actSelfType = _GET_PIPE_TYPE(actSelfVal);
    int actSelfPort = _GET_PIPE_DETAILPORT(actSelfVal);
    kal_int32 recv_total_len = 0;
    kal_int32 send_total_len = 0;
    bridge_node_struct_ptr bridge_peer_ptr = NULL;

    BRIDGE_TRACE(APP_BRIDGE_SEND_DATA_BY_TIMER);

    clear_soc_block_send_flag(bridge_info_ptr->reserved);
#ifdef BRIDGE_DATA_CHECK_PORT_TO_SOCKET
    g_trace_index++;
    g_work_item = 3;
    g_work_status[g_work_item + 3] = g_trace_index;
#endif /* BRIDGE_DATA_CHECK_PORT_TO_SOCKET */

    while(1)
    {
        send_total_len = sendPortDataByBridge(bridge_info_ptr);        
        bridge_peer_ptr = searchPeerInBridge(bridge_info_ptr->peerIndex);
        recv_total_len = recvDataFromPortByBridge(bridge_peer_ptr->peerIndex, bridge_info_ptr);        

        if( (0 >= send_total_len) && (0 >= recv_total_len) )
        {
            break;
        }
    }
}


void iot_timer_send_soc_cb(bridge_node_struct_ptr bridge_node_ptr)
{
    BRIDGE_TRACE(APP_BRIDGE_TIMER_CALLBACK, bridge_node_ptr->peerIndex);
    //because send data timer may occur before closing timer
    //invalidate bridge_node_ptr because already closed
    if(0 != bridge_node_ptr->peerIndex)
    {
        //check if closing flag has set
        if(0 != get_soc_close_flag(bridge_node_ptr->reserved) )
        {
            BRIDGE_TRACE(APP_BRIDGE_CLOSE);   
            closeBridge(bridge_node_ptr->peerIndex);
        }
        else
        {            
            sendDataFromPortByTimer(bridge_node_ptr);
        }
    }
    else
    {
        BRIDGE_TRACE(APP_BRIDGE_INVALIDATE_SOCKET);  
    }
   
}


/*****************************************************************************
* FUNCTION
*  sendLeftDataByBridgeInternal
* DESCRIPTION
*  only socket => uart transfer left data will use this method
* PARAMETERS
*  int actSelfPort, bridge_node_struct_ptr *peer_node_ptr
* RETURNS
*  void
*****************************************************************************/
static void sendLeftDataByBridgeInternal(bridge_node_struct_ptr peer_node_ptr)
{
    int sendLen = 0;
    int actSelfVal = peer_node_ptr->peerIndex;
    DataManagement *dataFLCPtr = (DataManagement*)(peer_node_ptr->firstPeerDataPtr);
    int left_data_len = 0;
    int actSelfType = _GET_PIPE_TYPE(actSelfVal); 
    int actSelfPort = _GET_PIPE_DETAILPORT(actSelfVal);
    bridge_node_struct_ptr sock_node_ptr = NULL;
    

    // change assert ********************************************
    if(NULL == dataFLCPtr)
    {
         BRIDGE_TRACE(APP_BRIDGE_NO_LEFT_DATA_SEND);
         return;
    }

    BRIDGE_TRACE(APP_BRIDGE_LEFT_SEND_DATA, actSelfVal, dataFLCPtr->totalDataLen,  dataFLCPtr->sendDataLen);

    while(NULL != dataFLCPtr)
    {
        left_data_len = dataFLCPtr->totalDataLen - dataFLCPtr->sendDataLen;            

        sendLen = writeUartByByte(actSelfPort, 
                                  (kal_uint8*)dataFLCPtr->dataPtr + dataFLCPtr->sendDataLen,
                                  left_data_len,
                                  MOD_SOC);

        //if uart lost, how to do?

        
#ifdef BRIDGE_DATA_CHECK            
        g_wifi_to_dcl_send_len += sendLen;
        BRIDGE_SEND_TRACE(APP_BRIDGE_AFTER_SEND_UART_DATA, g_wifi_to_dcl_send_len);
#endif /* BRIDGE_DATA_CHECK */            

       
        BRIDGE_TRACE(APP_BRIDGE_LEFT_TO_BRIDGE, actSelfType, left_data_len, sendLen, (kal_uint8*)dataFLCPtr->dataPtr + dataFLCPtr->sendDataLen);
        
        if(sendLen == left_data_len)
        {
            BRIDGE_TRACE( APP_BRIDGE_RELEASE_SOCKET_BUFFER, dataFLCPtr->headPtr);           

            ASSERT(NULL != dataFLCPtr->headPtr);
            iot_bridge_soc_free_mem(dataFLCPtr->headPtr);
           
            //free_ctrl_buffer(dataFLCPtr);
            BRIDGE_TRACE(APP_BRIDGE_RELEASE_PEER_NODE, peer_node_ptr);            
            //iot_bridge_free_mem(dataFLCPtr);
            release_bridge_node_data(peer_node_ptr);            
            
            dataFLCPtr = (DataManagement*)(peer_node_ptr->firstPeerDataPtr);            
        }
        else
        {
            BRIDGE_TRACE(APP_BRIDGE_NEED_NEXT_SEND, sendLen);
            //updateBridgeInfo
            if(0 < sendLen)
            {
                //peer_node_ptr->firstPeerDataPtr->sendDataLen += sendLen;
                dataFLCPtr->sendDataLen += sendLen;
            }            
            return;
        }        
    }

    sock_node_ptr = searchPeerInBridge(peer_node_ptr->peerIndex);
    if(0 != get_soc_close_flag(sock_node_ptr->reserved))
    {
        prepare_bridge_close(sock_node_ptr);
    }    
}


/*****************************************************************************
* FUNCTION
*  sendLeftPortDataByBridgeInternal()
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void sendLeftPortDataByBridgeInternal(int selfIndex)
{
    // bridge_node_struct_ptr bridge_node_ptr
    bridge_node_struct_ptr peer_node_ptr = searchSelfInBridge(selfIndex);

    BRIDGE_TRACE(APP_BRIDGE_SEND_LEFT_DATA_START);
  
    sendLeftDataByBridgeInternal(peer_node_ptr);

    BRIDGE_TRACE(APP_BRIDGE_SEND_LEFT_DATA_END);
}


/*****************************************************************************
* FUNCTION
*  freeBridgeItemNode
* DESCRIPTION
*  freeBridgeItemNode
* PARAMETERS
*  BridgeInfo *res
* RETURNS
*  void
*****************************************************************************/
static void freeBridgeItemNode(BridgeTableElement *tableBridgeElement, int peerType)
{
    DataManagement *PeerDataPtr = NULL;  
    int actSelfType = _GET_PIPE_TYPE(tableBridgeElement->peerIndex);
    int actSelfPort = _GET_PIPE_DETAILPORT(tableBridgeElement->peerIndex);    
    
    BRIDGE_TRACE(APP_BRIDGE_FREE_NODE_START, actSelfType,actSelfPort);

        
    if(SOCKET_PIPE_TYPE == peerType)
    {
        PeerDataPtr = (DataManagement*)tableBridgeElement->firstPeerDataPtr;
        while(NULL != PeerDataPtr)
        {
            iot_bridge_soc_free_mem(PeerDataPtr->headPtr);            
            release_bridge_node_data(tableBridgeElement);            
            PeerDataPtr = (DataManagement*)(tableBridgeElement->firstPeerDataPtr);
        }
    }
    else if( (UART_PIPE_TYPE == peerType) || (USB_PIPE_TYPE == peerType) )
    {
        if(SOCKET_PIPE_TYPE == actSelfType)
        {
            iot_bridge_free_mem(tableBridgeElement->bridgeDataHeadPtr);           
        }        
    }      

    BRIDGE_TRACE(APP_BRIDGE_CLOSE_PORT_START, actSelfPort);

    if(0 != get_bridge_validate_flag(tableBridgeElement->reserved))
    {
        // close uart
        if(UART_PIPE_TYPE == actSelfType)
        {      
            closeUart(actSelfPort, MOD_SOC);       
        }
        // close socket
        else if(SOCKET_PIPE_TYPE == actSelfType)
        {      
            soc_close(actSelfPort);        
        }
        // close usb
        else if(USB_PIPE_TYPE == actSelfType)
        {        
            closeUsb(actSelfPort, MOD_SOC);        
        }         
    }
    else
    {
        BRIDGE_TRACE(APP_BRIDGE_CLOSE_UNINITIZE);
    }

    tableBridgeElement->peerIndex = 0;
    tableBridgeElement->firstPeerDataPtr = NULL;
    tableBridgeElement->lastPeerDataPtr = NULL; 
    tableBridgeElement->bridgeDataHeadPtr = NULL; 
    tableBridgeElement->reserved = 0;   
    
    BRIDGE_TRACE(APP_BRIDGE_CLOSE_PORT_END);
}


/*****************************************************************************
* FUNCTION
*  destroyBridgeItem
* DESCRIPTION
*  destroyBridgeItem
* PARAMETERS
*  Bint index
* RETURNS
*  void
*****************************************************************************/
static void destroyBridgeItem(int index)
{
    //if there is has some data left should also cleared
    int firPeerType = _GET_PIPE_TYPE(g_brideg_table[index].firstBridgeItem.peerIndex);
    int secPeerType = _GET_PIPE_TYPE(g_brideg_table[index].secondBridgeItem.peerIndex);
    freeBridgeItemNode(&g_brideg_table[index].firstBridgeItem, secPeerType);
    freeBridgeItemNode(&g_brideg_table[index].secondBridgeItem, firPeerType);
}


/*****************************************************************************
* FUNCTION
*  closeBridge
* DESCRIPTION
*  createBridge
*  for app use
* PARAMETERS
*  BridgeInfo *res
* RETURNS
*  void
*****************************************************************************/
void closeBridge(int peerIndex)
{
    int index = 0;

    BRIDGE_TRACE(APP_BRIDGE_CLOSE_BRIDGE_START);
    
    for(index = 0; index < MAXPIPENUM; ++index)
    {
        if( (peerIndex == g_brideg_table[index].firstBridgeItem.peerIndex)
            || (peerIndex == g_brideg_table[index].secondBridgeItem.peerIndex) )
        {
           destroyBridgeItem(index);
        }
    }

    BRIDGE_TRACE(APP_BRIDGE_CLOSE_BRIDGE_END);
}


/*****************************************************************************
* FUNCTION
*  initBridge
* DESCRIPTION
*  getPipeID
* PARAMETERS
*  BridgeInfo *res
* RETURNS
*  void
*****************************************************************************/
static int getPipeID(BridgePeerInfo *bridgePeerInfo)
{
    int detail_id = INVALIDATEINDEX;
      
    switch(bridgePeerInfo->type)
    {
    case SOCKET_PIPE_TYPE:
        detail_id = bridgePeerInfo->TypeInfo.socketInfo.socket_accpet_fd;
        break;
    case UART_PIPE_TYPE:
        detail_id = bridgePeerInfo->TypeInfo.uartInfo.uart_port;
        break;
    case USB_PIPE_TYPE: 
        detail_id = bridgePeerInfo->TypeInfo.usbInfo.usb_port;
        break;
    default:
        break;
    }

    BRIDGE_TRACE(APP_BRIDGE_GET_PORT_ID, detail_id);
    
    if(INVALIDATEINDEX == detail_id)
    {
        /* insert log */
        BRIDGE_TRACE(APP_BRIDGE_GET_PORT_INVALIDATE);
        return INVALIDATEINDEX;
    }

    /* insert log */
    
    detail_id = _PIPE_ID(bridgePeerInfo->type, detail_id);

    BRIDGE_TRACE(APP_BRIDGE_GET_PORT_DETAIL_ID, detail_id);
    
    return detail_id;
}


/*****************************************************************************
* FUNCTION
*  getFirstCanUseBridgeIndex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static int getFirstCanUseBridgeIndex(int firPeerIndex, int secPeerIndex)
{
    int index = 0;
    int retIndex = INVALIDATEINDEX;
    
    for(index = 0; index < MAXPIPENUM; ++index)
    {        
        if(INVALIDATEINDEX == retIndex)
        {
            if( (0 == g_brideg_table[index].firstBridgeItem.peerIndex)
                && (0 == g_brideg_table[index].secondBridgeItem.peerIndex) )
            {
                retIndex = index;                
            }
        }        
    }   
    
    return retIndex;
}



static int searchBridgeIndex(int firPeerIndex, int secPeerIndex)
{
    int index = 0;
    int retIndex = INVALIDATEINDEX;
    
    for(index = 0; index < MAXPIPENUM; ++index)
    {
        if( (firPeerIndex == g_brideg_table[index].firstBridgeItem.peerIndex)
             || (secPeerIndex == g_brideg_table[index].firstBridgeItem.peerIndex)
             || (firPeerIndex == g_brideg_table[index].secondBridgeItem.peerIndex)
             || (secPeerIndex == g_brideg_table[index].secondBridgeItem.peerIndex) )
        {          
            return index;
        }
    }
     return INVALIDATEINDEX;
}
        

/*****************************************************************************
* FUNCTION
*  initBridgeItemInternal
* DESCRIPTION
*  insert item in bridge table
* use this API must guarantee index parameter is validate
* PARAMETERS
*  int index, int peerFirIndex, int peerSecIndex
* RETURNS
*  void
*****************************************************************************/
static void initBridgeItemInternal(bridge_node_struct_ptr bridge_node_ptr, int peerNodeType)
{
    int selfIndex = bridge_node_ptr->peerIndex;    
    
    if( SOCKET_PIPE_TYPE == _GET_PIPE_TYPE(selfIndex) )
    {
        if(SOCKET_PIPE_TYPE == peerNodeType)
        {
            initBridgeTransferNodeData(bridge_node_ptr);
            BRIDGE_TRACE(APP_BRIDGE_INIT_SOCK_TO_SOCK);
        }
        else if(UART_PIPE_TYPE == peerNodeType)
        {
            initBridgeTransferData(bridge_node_ptr);
            BRIDGE_TRACE(APP_BRIDGE_INIT_SOCK_TO_UART);
        }
        else if(USB_PIPE_TYPE == peerNodeType)
        {
            initBridgeTransferData(bridge_node_ptr);
            BRIDGE_TRACE(APP_BRIDGE_INIT_SOCK_TO_USB);
        } 
    }
    else if(UART_PIPE_TYPE == _GET_PIPE_TYPE(selfIndex))
    {
        // only support uart to socket bridge
        initBridgeTransferNodeData(bridge_node_ptr);
        BRIDGE_TRACE(APP_BRIDGE_INIT_UART_TO_SOCKET);
    }
    else if(USB_PIPE_TYPE == _GET_PIPE_TYPE(selfIndex))
    {
        // only support usb to socket bridge
        initBridgeTransferNodeData(bridge_node_ptr);
        BRIDGE_TRACE(APP_BRIDGE_INIT_USB_TO_SOCKET);
    }
}


/*****************************************************************************
* FUNCTION
*  initBridgeItem
* DESCRIPTION
*  insert item in bridge table
* use this API must guarantee index parameter is validate
* PARAMETERS
*  int index, int peerFirIndex, int peerSecIndex
* RETURNS
*  void
*****************************************************************************/
static void initBridgeItem(int index, int peerFirIndex, int peerSecIndex)
{
    g_brideg_table[index].firstBridgeItem.peerIndex = peerFirIndex;
    g_brideg_table[index].firstBridgeItem.reserved = 0;    
    initBridgeItemInternal(&g_brideg_table[index].firstBridgeItem, _GET_PIPE_TYPE(peerSecIndex));

    g_brideg_table[index].secondBridgeItem.peerIndex = peerSecIndex;    
    g_brideg_table[index].secondBridgeItem.reserved = 0;
    initBridgeItemInternal(&g_brideg_table[index].secondBridgeItem, _GET_PIPE_TYPE(peerFirIndex));
}


/*****************************************************************************
* FUNCTION
*  initBridge
* DESCRIPTION
*  Insert g_brideg_table
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void initBridge()
{
    int index = 0;
    for(index = 0; index < MAXPIPENUM; ++index)
    {
        g_brideg_table[index].firstBridgeItem.peerIndex = 0;
        g_brideg_table[index].firstBridgeItem.firstPeerDataPtr = NULL;
        g_brideg_table[index].firstBridgeItem.lastPeerDataPtr = NULL;
        g_brideg_table[index].firstBridgeItem.bridgeDataHeadPtr = NULL;
        g_brideg_table[index].firstBridgeItem.reserved = 0;

        g_brideg_table[index].secondBridgeItem.peerIndex = 0;
        g_brideg_table[index].secondBridgeItem.firstPeerDataPtr = NULL;
        g_brideg_table[index].secondBridgeItem.lastPeerDataPtr = NULL;
        g_brideg_table[index].secondBridgeItem.bridgeDataHeadPtr = NULL;
        g_brideg_table[index].secondBridgeItem.reserved = 0;
    }
}

   
/*****************************************************************************
* FUNCTION
*  insertPipeTable
* DESCRIPTION
*  Insert g_brideg_table
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static int insertPipeTable(int firstPeerIndex, int secondPeerIndex)
{   
    int searchIndex = searchBridgeIndex(firstPeerIndex, secondPeerIndex);

    if(searchIndex == INVALIDATEINDEX)
    {
        searchIndex = getFirstCanUseBridgeIndex(firstPeerIndex, secondPeerIndex);
        if(searchIndex != INVALIDATEINDEX)
        {
            initBridgeItem(searchIndex, firstPeerIndex, secondPeerIndex);
            BRIDGE_TRACE(APP_BRIDGE_INIT_INSERT_NODE_DIRECT);
        }        
    }
    else
    {
        destroyBridgeItem(searchIndex);
        initBridgeItem(searchIndex, firstPeerIndex, secondPeerIndex);
        BRIDGE_TRACE(APP_BRIDGE_INIT_INSERT_NODE_INDIRECT,searchIndex, firstPeerIndex, secondPeerIndex);
    }
    return searchIndex;
}


#endif __LOW_LEVEL_BRIDGE_SUPPORT__
