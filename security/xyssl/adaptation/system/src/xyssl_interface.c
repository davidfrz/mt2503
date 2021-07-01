#include "xyssl_interface.h"
#include "xyssl_x509.h"
#include "xyssl_base64.h"
#include "xyssl_sha1.h"
#include "kal_trace.h"

int xyssl_num_active = 0;

 int xyssl_adp_ssl_init( ssl_context *ssl, xyssl_adp_malloc_cb alloc , xyssl_adp_free_cb free ,void* user_data)
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
	int ret = 0;
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_init: %x",ssl);

   memset( ssl, 0, sizeof( ssl_context ) );
   
	ssl->alloc = alloc;
	ssl->free = free; 
	ssl->user_data = user_data;
	
 	 if((ret = ssl_init(ssl)) == 0)
	 {
	 	xyssl_num_active++;
		ssl_set_rng( ssl, xyssl_adp_RAND, NULL );
		ssl_set_ciphers( ssl, ssl_default_ciphers );
 	 	}
	 
	 kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_init: %x xyssl_num_active:%d",ssl,xyssl_num_active);
	 return ret;
 }

 void xyssl_adp_ssl_deinit( ssl_context *ssl )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	xyssl_num_active--;
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_init: %x xyssl_num_active:%d",ssl,xyssl_num_active);	

	ssl_free(ssl);
	ssl->alloc = NULL;
	ssl->free = NULL;
	ssl->user_data = NULL;
 }
 
 void xyssl_adp_ssl_set_endpoint( ssl_context *ssl, int endpoint )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_set_endpoint: %x",ssl);
 	ssl_set_endpoint(ssl,endpoint);
 }
 
 void xyssl_adp_ssl_set_authmode( ssl_context *ssl, int authmode )
 {
 	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_set_authmode: %x",ssl);
 	ssl_set_authmode(ssl,authmode);
 }
 
 void xyssl_adp_ssl_set_bio( ssl_context *ssl,                       
        int (*f_recv)(void *, unsigned char *, int), void *p_recv,
        int (*f_send)(void *, unsigned char *, int), void *p_send )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_set_bio: %x",ssl);
 	ssl_set_bio(ssl,f_recv,p_recv,f_send,p_send);
 }
 
 void xyssl_adp_ssl_set_session( ssl_context *ssl, int resume, int timeout,      
                      ssl_session *session )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_set_session: %x",ssl);
	
 	ssl_set_session(ssl,resume,timeout,session);
 }
 
 void xyssl_adp_md5_hash(unsigned char *input, int ilen, unsigned char output[16])
{
	xyssl_md5( input, ilen, output );
}
 
 void xyssl_adp_ssl_set_ca_chain( ssl_context *ssl, x509_cert *ca_chain,
                       char *peer_cn )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_set_ca_chain: %x",ssl);
	
 	ssl_set_ca_chain(ssl,ca_chain,peer_cn);
 }
 
 char *xyssl_adp_ssl_get_cipher( ssl_context *ssl )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_get_cipher: %x",ssl);
	
 	return ssl_get_cipher(ssl);
 }
 
 int xyssl_adp_ssl_handshake( ssl_context *ssl )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_handshake: %x",ssl);
 	return ssl_handshake(ssl);
 }
 
 int xyssl_adp_ssl_read( ssl_context *ssl, unsigned char *buf, int len )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_read: %x",ssl);
 	return ssl_read(ssl,buf,len);
 }
 
 int xyssl_adp_ssl_write( ssl_context *ssl, unsigned char *buf, int len )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_write: %x",ssl);
 	return ssl_write(ssl,buf,len);
 }


   int xyssl_adp_ssl_close_notify( ssl_context *ssl )
  {
	 /*----------------------------------------------------------------*/
   /* Local Variables												 */
   /*----------------------------------------------------------------*/
   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/
	 kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_close_notify: %x",ssl);
	 return ssl_close_notify(ssl);
  }

 
 
 int xyssl_adp_base64_encode( unsigned char *dst, int *dlen,
                   unsigned char *src, int  slen )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
 	return xyssl_base64_encode(dst,dlen,src,slen);
 }
 
 int xyxxl_adp_base64_decode( unsigned char *dst, int *dlen,
                   unsigned char *src, int  slen )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
 	return base64_decode(dst,dlen,src,slen);
 }
 
 void xyssl_adp_sha1_hmac( unsigned char *key, int keylen,
                unsigned char *input, int ilen,
                unsigned char output[20] )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
 	sha1_hmac(key,keylen,input,ilen,output);
 }
 
 int xyssl_adp_x509parse_crt(ssl_context *ssl, x509_cert *crt, unsigned char *buf, int buflen )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_x509parse_crt: %x",ssl);
 	return x509parse_crt(ssl,crt,buf,buflen);
 }
 
 void xyssl_adp_x509_free(ssl_context *ssl, x509_cert *crt )
 {
 	/*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
	kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_x509_free: %x",ssl);
 	x509_free(ssl,crt);
 }

  int xyssl_adp_ssl_get_verify_result( ssl_context *ssl )
  {
	 /*----------------------------------------------------------------*/
   /* Local Variables												 */
   /*----------------------------------------------------------------*/
   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/
	 kal_wap_trace(MOD_WPS,TRACE_STATE,"xyssl_adp_ssl_get_verify_result: %x",ssl);
	 ssl_get_verify_result(ssl);
  }


 
