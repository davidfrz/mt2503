#ifndef __GPS_H__
#define __GPS_H__

#include "mmi_features.h"

#if defined(__MMI_INTELL_LOCATION__)&&defined(__GPS_SUPPORT__) 
#include "MMIDataType.h"

/*数据类型*/
typedef struct{
    FLOAT longitude;	/*经度*/
    FLOAT	latitude;   /*纬度*/
    S8	north_south;    /*北-南*/
    S8	east_west;      /*东-西*/
}stu_gps_data;	

typedef struct
{
    S32 port; /*GPS 工作端口 */
    S32 port.handle; /*-l:GPS关闭状态；否则GPS处于打开状态*/ 
}stu_gps_handle;

/*函数接口*/
/*********************************************
 * *mmi_gps_get_data
 * func: gps数据
 * para: void
 * return: gps数据
 *********************************************/
extern stu_gps_data *mmi_gps_get_data(void); 

/*********************************************
 * mmi_gps_open
 * func: 打开gps
 * para: void
 * return: void
 *********************************************/
extern void mmi_gps_open(void);

/*********************************************
 * mmi_gps_close
 * func: 关闭GPS
 * para: void
 * return: void
 *********************************************/
extern void mmi_gps_close(void);

#endif
#endif /*__GPS_H__*/

