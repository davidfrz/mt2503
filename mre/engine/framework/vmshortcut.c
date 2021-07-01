#include "string.h"
#include "vmcerter.h"
#include "vmsys.h"
#include "vmres.h"
#include "vmgettag.h"
#include "vmcert.h"
#include "vmcermng.h"

VMINT vm_get_appicon( VMWSTR vxp_filename, VMSTR icon_ptr, VMINT size)
{
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return 0;
}


VMINT vm_get_appid(VMWSTR vxp_filename)
{
	VMINT res = 0, buf_size = sizeof(VMINT), buf = 0;
	
	if( vxp_filename == NULL )
		return 0;
	
	res = vm_get_vm_tag( vxp_filename, VM_CE_INFO_APP_ID, (VMCHAR *)&buf, &buf_size );
	
	if( res == GET_TAG_TRUE )
		return buf;
	else
		return 0;
}


/*VMINT vm_app_is_valid(VMWSTR vxp_filename)
{
	VMUCHAR* ce_digest_buffer = NULL;
	VMINT ce_digest_buffer_len = (10 * 1024);
	VMUCHAR appdigest[16];
	MRECert* cert = NULL;
	VMINT rescode = vm_ce_init();

	if( vxp_filename )
	{
		if( rescode < 0 )
		{
			vm_ce_finialize();
		
			return rescode;
		}

		if ((ce_digest_buffer = vm_malloc(ce_digest_buffer_len)) == NULL)
		{
			vm_ce_finialize();
			return VM_CE_VERIFY_BAD_DIGEST;
		}
		
		if( vm_parse_exec_format( filename ) == VM_EXEC_ROM )
		{
			VMUINT8 *	rom = vm_get_execrom_ptr( filename );	
			VMINT		size = vm_get_execrom_size( rom - 4 );
	
			vm_log_debug( "size = %d, rom=%x", size, rom );
	
			//caculate the digest and read the cert
			vm_ce_get_app_digest_rom( (VMCHAR *)rom, size, appdigest );
			apce = vm_ce_load_app_rom( (VMCHAR *)rom, size );
	
			//verify the app	
			if( apce )
				rescode = vm_ce_verify_app( apce, (VMUCHAR *)appdigest, DIG_MAX_LEN, mode );
			else
				rescode = -1;	
	
			vm_ce_unload_app( apce );
			vm_ce_finialize( );		
				
			return rescode;
		}
		else
		{		
			if (vm_ce_get_app_digest(vxp_filename, ce_digest_buffer, ce_digest_buffer_len, appdigest) != VM_CE_OP_OK)
			{	
				vm_ce_finialize();
				vm_free(ce_digest_buffer);
				return VM_CE_VERIFY_BAD_DIGEST;
			}
			vm_free(ce_digest_buffer);
	     	
			cert = (MRECert*)vm_ce_load_app(vxp_filename);
	
			if(cert)
			{
				//ignore the mem check when creating shortcut
				cert->checkfunc[VM_CE_INFO_MEM_REQ] = NULL;
				
				rescode = vm_ce_verify_app(cert, (VMUCHAR*)appdigest, 16, VERIFY_FULL);
			}
			else
			{
				vm_ce_unload_app(cert);
				vm_ce_finialize();		
		
				return VM_CE_VERIFY_BAD_DIGEST;
			}
	
			vm_ce_unload_app(cert);
			vm_ce_finialize();
	
			return rescode;
		}
	}
	else
		return VM_CE_VERIFY_BAD_PARAM;
}*/

VMINT vm_app_is_valid(VMWSTR vxp_filename)
{
	VMUCHAR* ce_digest_buffer = NULL;
	VMINT ce_digest_buffer_len = (10 * 1024);
	
	VMINT	rescode = -1;
	
	if( vxp_filename )
	{
		if ((ce_digest_buffer = vm_malloc(ce_digest_buffer_len)) == NULL)
			return VM_CE_VERIFY_BAD_DIGEST;
		#ifdef __MRE_CORE_SAFETY__
		rescode = vm_ce_auth_app( vxp_filename, ce_digest_buffer, ce_digest_buffer_len );
		#else
		rescode = VM_CE_VERIFY_OK;
		#endif
		//vm_per_finalize( );
		
		vm_free( ce_digest_buffer );
		
		return rescode;
	}	
	else
		return VM_CE_VERIFY_BAD_PARAM;
}
