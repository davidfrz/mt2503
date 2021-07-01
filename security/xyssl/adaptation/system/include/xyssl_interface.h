/**
 * \file xyssl_interface.h
 */
#ifndef XYSSL_INTERFACE_H
#define XYSSL_INTERFACE_H

#include "xyssl_ssl.h"
#include "xyssl_mem.h"
#include "xyssl_time.h"


/*
 * Rteurn Errror Values from Xyssl Library
 */
#define XYSSL_ADP_ERR_SSL_FEATURE_UNAVAILABLE               -0x1000
#define XYSSL_ADP_ERR_SSL_BAD_INPUT_DATA                	-0x1800
#define XYSSL_ADP_ERR_SSL_INVALID_MAC                       -0x2000
#define XYSSL_ADP_ERR_SSL_INVALID_RECORD                	-0x2800
#define XYSSL_ADP_ERR_SSL_INVALID_MODULUS_SIZE          	-0x3000
#define XYSSL_ADP_ERR_SSL_UNKNOWN_CIPHER                    -0x3800
#define XYSSL_ADP_ERR_SSL_NO_CIPHER_CHOSEN                  -0x4000
#define XYSSL_ADP_ERR_SSL_NO_SESSION_FOUND                  -0x4800
#define XYSSL_ADP_ERR_SSL_NO_CLIENT_CERTIFICATE             -0x5000
#define XYSSL_ADP_ERR_SSL_CERTIFICATE_TOO_LARGE             -0x5800
#define XYSSL_ADP_ERR_SSL_CERTIFICATE_REQUIRED              -0x6000
#define XYSSL_ADP_ERR_SSL_PRIVATE_KEY_REQUIRED              -0x6800
#define XYSSL_ADP_ERR_SSL_CA_CHAIN_REQUIRED                 -0x7000
#define XYSSL_ADP_ERR_SSL_UNEXPECTED_MESSAGE                -0x7800
#define XYSSL_ADP_ERR_SSL_FATAL_ALERT_MESSAGE               -0x8000
#define XYSSL_ADP_ERR_SSL_PEER_VERIFY_FAILED                -0x8800
#define XYSSL_ADP_ERR_SSL_PEER_CLOSE_NOTIFY                 -0x9000
#define XYSSL_ADP_ERR_SSL_BAD_HS_CLIENT_HELLO               -0x9800
#define XYSSL_ADP_ERR_SSL_BAD_HS_SERVER_HELLO               -0xA000
#define XYSSL_ADP_ERR_SSL_BAD_HS_CERTIFICATE                -0xA800
#define XYSSL_ADP_ERR_SSL_BAD_HS_CERTIFICATE_REQUEST        -0xB000
#define XYSSL_ADP_ERR_SSL_BAD_HS_SERVER_KEY_EXCHANGE        -0xB800
#define XYSSL_ADP_ERR_SSL_BAD_HS_SERVER_HELLO_DONE          -0xC000
#define XYSSL_ADP_ERR_SSL_BAD_HS_CLIENT_KEY_EXCHANGE        -0xC800
#define XYSSL_ADP_ERR_SSL_BAD_HS_CERTIFICATE_VERIFY         -0xD000
#define XYSSL_ADP_ERR_SSL_BAD_HS_CHANGE_CIPHER_SPEC         -0xD800
#define XYSSL_ADP_ERR_SSL_BAD_HS_FINISHED                   -0xE000


/*
*     XYSSL VERIFY RESULT ERROR VALUES
*/
#define XYSSL_ADP_BADCERT_EXPIRED             0x01  /**< The certificate validity has expired. */
#define XYSSL_ADP_BADCERT_REVOKED             0x02  /**< The certificate has been revoked (is on a CRL). */
#define XYSSL_ADP_BADCERT_CN_MISMATCH         0x04  /**< The certificate Common Name (CN) does not match with the expected CN. */
#define XYSSL_ADP_BADCERT_NOT_TRUSTED         0x08  /**< The certificate is not correctly signed by the trusted CA. */


/*
*     XYSSL X509 ERROR VALUES
*/
#define XYSSL_ADP_ERR_X509_FEATURE_UNAVAILABLE              -0x0020
#define XYSSL_ADP_ERR_X509_CERT_INVALID_PEM                 -0x0040
#define XYSSL_ADP_ERR_X509_CERT_INVALID_FORMAT              -0x0060
#define XYSSL_ADP_ERR_X509_CERT_INVALID_VERSION             -0x0080
#define XYSSL_ADP_ERR_X509_CERT_INVALID_SERIAL              -0x00A0
#define XYSSL_ADP_ERR_X509_CERT_INVALID_ALG                 -0x00C0
#define XYSSL_ADP_ERR_X509_CERT_INVALID_NAME                -0x00E0
#define XYSSL_ADP_ERR_X509_CERT_INVALID_DATE                -0x0100
#define XYSSL_ADP_ERR_X509_CERT_INVALID_PUBKEY              -0x0120
#define XYSSL_ADP_ERR_X509_CERT_INVALID_SIGNATURE           -0x0140
#define XYSSL_ADP_ERR_X509_CERT_INVALID_EXTENSIONS          -0x0160
#define XYSSL_ADP_ERR_X509_CERT_UNKNOWN_VERSION             -0x0180
#define XYSSL_ADP_ERR_X509_CERT_UNKNOWN_SIG_ALG             -0x01A0
#define XYSSL_ADP_ERR_X509_CERT_UNKNOWN_PK_ALG              -0x01C0
#define XYSSL_ADP_ERR_X509_CERT_SIG_MISMATCH                -0x01E0
#define XYSSL_ADP_ERR_X509_CERT_VERIFY_FAILED               -0x0200
#define XYSSL_ADP_ERR_X509_KEY_INVALID_PEM                  -0x0220
#define XYSSL_ADP_ERR_X509_KEY_INVALID_VERSION              -0x0240
#define XYSSL_ADP_ERR_X509_KEY_INVALID_FORMAT               -0x0260
#define XYSSL_ADP_ERR_X509_KEY_INVALID_ENC_IV               -0x0280
#define XYSSL_ADP_ERR_X509_KEY_UNKNOWN_ENC_ALG              -0x02A0
#define XYSSL_ADP_ERR_X509_KEY_PASSWORD_REQUIRED            -0x02C0
#define XYSSL_ADP_ERR_X509_KEY_PASSWORD_MISMATCH            -0x02E0
#define XYSSL_ADP_ERR_X509_POINT_ERROR                      -0x0300
#define XYSSL_ADP_ERR_X509_VALUE_TO_LENGTH                  -0x0320


/*
*    XYSSL BASE64 ERROR VALUES
*/
#define XYSSL_ADP_ERR_BASE64_BUFFER_TOO_SMALL               -0x0010
#define XYSSL_ADP_ERR_BASE64_INVALID_CHARACTER              -0x0012


typedef struct 
{
	ssl_session    xyssl_adp_ssn;
	ssl_context    xyssl_adp_cntx;
	x509_cert      xyssl_ca_chain;
}xyssl_adp_context_struct;

/*
 * Various constants
 */
#define XYSSL_ADP_SSL_IS_CLIENT                   0  
#define XYSSL_ADP_SSL_IS_SERVER                   1
#define XYSSL_ADP_SSL_COMPRESS_NULL               0

#define XYSSL_ADP_SSL_VERIFY_NONE                 0  
#define XYSSL_ADP_SSL_VERIFY_OPTIONAL             1
#define XYSSL_ADP_SSL_VERIFY_REQUIRED             2


/*********************************** XYSSL Interfaces ************************************/

/**
 * \brief          Initialize an SSL context
 *
 * \param ssl      SSL context
 * \param alloc  Memory allocate callback function     
 * \param free   Memory Free callback function
 *
 * \return         0 if successful, 1 if memory allocation failed ,-1 failed for some other reason
 */
 int xyssl_adp_ssl_init( ssl_context *ssl, xyssl_adp_malloc_cb alloc , xyssl_adp_free_cb free ,void* user_data);                    

/**
 * \brief          Set the current endpoint type
 *
 * \param ssl      SSL context
 * \param endpoint must be SSL_IS_CLIENT or SSL_IS_SERVER
 */
 void xyssl_adp_ssl_set_endpoint( ssl_context *ssl, int endpoint );         

/**
 * \brief          Set the certificate verification mode
 *
 * \param ssl      SSL context
 * \param mode     can be:
 *
 *  SSL_VERIFY_NONE:      peer certificate is not checked (default),
 *                        this is insecure and SHOULD be avoided.
 *
 *  SSL_VERIFY_OPTIONAL:  peer certificate is checked, however the
 *                        handshake continues even if verification failed;
 *                        ssl_get_verify_result() can be called after the
 *                        handshake is complete.
 *
 *  SSL_VERIFY_REQUIRED:  peer *must* present a valid certificate,
 *                        handshake is aborted if verification failed.
 */
 void xyssl_adp_ssl_set_authmode( ssl_context *ssl, int authmode );         


/**
 * \brief          Set the underlying BIO read and write callbacks
 *
 * \param ssl      SSL context
 * \param f_recv   read callback
 * \param p_recv   read parameter
 * \param f_send   write callback
 * \param p_send   write parameter
 */
  void xyssl_adp_ssl_set_bio( ssl_context *ssl,                       
        int (*f_recv)(void *, unsigned char *, int), void *p_recv,
        int (*f_send)(void *, unsigned char *, int), void *p_send );


/**
 * \brief          Set the session resuming flag, timeout and data
 *
 * \param ssl      SSL context
 * \param resume   if 0 (default), the session will not be resumed
 * \param timeout  session timeout in seconds, or 0 (no timeout)
 * \param session  session context
 */
 void xyssl_adp_ssl_set_session( ssl_context *ssl, int resume, int timeout,      
                      ssl_session *session );

/*****************************************************************************
 * FUNCTION
 *  stk_tls_adp_md5_hash
 * DESCRIPTION
 *  Calculate hash of input
 * PARAMETERS
 *  None   
 * RETURNS
 *  None
 *****************************************************************************/
void xyssl_adp_md5_hash(unsigned char *input, int ilen, unsigned char output[16]);
/**
 * \brief          Set the data required to verify peer certificate
 *
 * \param ssl      SSL context
 * \param ca_chain trusted CA chain
 * \param peer_cn  expected peer CommonName (or NULL)
 *
 * \note           TODO: add two more parameters: depth and crl
 */
  void xyssl_adp_ssl_set_ca_chain( ssl_context *ssl, x509_cert *ca_chain,
                       char *peer_cn );


/**
 * \brief          Return the name of the current cipher
 *
 * \param ssl      SSL context
 *
 * \return         a string containing the cipher name
 */
  char *xyssl_adp_ssl_get_cipher( ssl_context *ssl );


/**
 * \brief          Perform the SSL handshake
 *
 * \param ssl      SSL context
 *
 * \return         0 if successful, XYSSL_ERR_NET_TRY_AGAIN,
 *                 or a specific SSL error code.
 */
  int xyssl_adp_ssl_handshake( ssl_context *ssl );           


/**
 * \brief          Read at most 'len' application data bytes
 *
 * \param ssl      SSL context
 * \param buf      buffer that will hold the data
 * \param len      how many bytes must be read
 *
 * \return         This function returns the number of bytes read,
 *                 or a negative error code.
 */
  int xyssl_adp_ssl_read( ssl_context *ssl, unsigned char *buf, int len );  


/**
 * \brief          Write exactly 'len' application data bytes
 *
 * \param ssl      SSL context
 * \param buf      buffer holding the data
 * \param len      how many bytes must be written
 *
 * \return         This function returns the number of bytes written,
 *                 or a negative error code.
 *
 * \note           When this function returns XYSSL_ERR_NET_TRY_AGAIN,
 *                 it must be called later with the *same* arguments,
 *                 until it returns a positive value.
 */
  int xyssl_adp_ssl_write( ssl_context *ssl, unsigned char *buf, int len );


/**
 * \brief          Notify the peer that the connection is being closed
 */
  int xyssl_adp_ssl_close_notify( ssl_context *ssl );


/**
 * \brief          Free an SSL context
 */
  void xyssl_adp_ssl_deinit( ssl_context *ssl );     
   

   
   
/**
 * \brief          Encode a buffer into base64 format
 *
 * \param dst      destination buffer
 * \param dlen     size of the buffer
 * \param src      source buffer
 * \param slen     amount of data to be encoded
 *
 * \return         0 if successful, or XYSSL_ERR_BASE64_BUFFER_TOO_SMALL.
 *                 *dlen is always updated to reflect the amount
 *                 of data that has (or would have) been written.
 *
 * \note           Call this function with *dlen = 0 to obtain the
 *                 required buffer size in *dlen
 */
int xyssl_adp_base64_encode( unsigned char *dst, int *dlen,
                   unsigned char *src, int  slen );
                   
                  
/**
 * \brief          Decode a base64-formatted buffer
 *
 * \param dst      destination buffer
 * \param dlen     size of the buffer
 * \param src      source buffer
 * \param slen     amount of data to be decoded
 *
 * \return         0 if successful, XYSSL_ERR_BASE64_BUFFER_TOO_SMALL, or
 *                 XYSSL_ERR_BASE64_INVALID_DATA if the input data is not
 *                 correct. *dlen is always updated to reflect the amount
 *                 of data that has (or would have) been written.
 *
 * \note           Call this function with *dlen = 0 to obtain the
 *                 required buffer size in *dlen
 */
int xyxxl_adp_base64_decode( unsigned char *dst, int *dlen,
                   unsigned char *src, int  slen );
                   
                   
/**
 * \brief          Output = HMAC-SHA-1( hmac key, input buffer )
 *
 * \param key      HMAC secret key
 * \param keylen   length of the HMAC key
 * \param input    buffer holding the  data
 * \param ilen     length of the input data
 * \param output   HMAC-SHA-1 result
 */
void xyssl_adp_sha1_hmac( unsigned char *key, int keylen,
                unsigned char *input, int ilen,
                unsigned char output[20] );
/**
 * \brief          Parse one or more certificates and add them
 *                 to the chained list
 *
 * \param chain    points to the start of the chain
 * \param buf      buffer holding the certificate data
 * \param buflen   size of the buffer
 *
 * \return         0 if successful, or a specific X509 error code
 */
int xyssl_adp_x509parse_crt(ssl_context *ssl, x509_cert *crt, unsigned char *buf, int buflen );

/**
 * \brief          Unallocate all certificate data
 */
void xyssl_adp_x509_free(ssl_context *ssl, x509_cert *crt );

/**
 * \brief          Return the result of the certificate verification
 *
 * \param ssl      SSL context
 *
 * \return         0 if successful, or a combination of:
 *                      XYSSL_ADP_BADCERT_EXPIRED
 *                      XYSSL_ADP_BADCERT_REVOKED
 *                      XYSSL_ADP_BADCERT_CN_MISMATCH
 *                      XYSSL_ADP_BADCERT_NOT_TRUSTED
 */
int xyssl_adp_ssl_get_verify_result( ssl_context *ssl );

#endif //End XYSSL_INTERFACE_H