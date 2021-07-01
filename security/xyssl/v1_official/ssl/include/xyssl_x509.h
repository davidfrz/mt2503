/**
 * \file x509.h
 */
#ifndef XYSSL_X509_H
#define XYSSL_X509_H

#include "xyssl_rsa.h"

#define XYSSL_ERR_ASN1_OUT_OF_DATA                      -0x0014
#define XYSSL_ERR_ASN1_UNEXPECTED_TAG                   -0x0016
#define XYSSL_ERR_ASN1_INVALID_LENGTH                   -0x0018
#define XYSSL_ERR_ASN1_LENGTH_MISMATCH                  -0x001A
#define XYSSL_ERR_ASN1_INVALID_DATA                     -0x001C

#define XYSSL_ERR_X509_FEATURE_UNAVAILABLE              -0x0020
#define XYSSL_ERR_X509_CERT_INVALID_PEM                 -0x0040
#define XYSSL_ERR_X509_CERT_INVALID_FORMAT              -0x0060
#define XYSSL_ERR_X509_CERT_INVALID_VERSION             -0x0080
#define XYSSL_ERR_X509_CERT_INVALID_SERIAL              -0x00A0
#define XYSSL_ERR_X509_CERT_INVALID_ALG                 -0x00C0
#define XYSSL_ERR_X509_CERT_INVALID_NAME                -0x00E0
#define XYSSL_ERR_X509_CERT_INVALID_DATE                -0x0100
#define XYSSL_ERR_X509_CERT_INVALID_PUBKEY              -0x0120
#define XYSSL_ERR_X509_CERT_INVALID_SIGNATURE           -0x0140
#define XYSSL_ERR_X509_CERT_INVALID_EXTENSIONS          -0x0160
#define XYSSL_ERR_X509_CERT_UNKNOWN_VERSION             -0x0180
#define XYSSL_ERR_X509_CERT_UNKNOWN_SIG_ALG             -0x01A0
#define XYSSL_ERR_X509_CERT_UNKNOWN_PK_ALG              -0x01C0
#define XYSSL_ERR_X509_CERT_SIG_MISMATCH                -0x01E0
#define XYSSL_ERR_X509_CERT_VERIFY_FAILED               -0x0200
#define XYSSL_ERR_X509_KEY_INVALID_PEM                  -0x0220
#define XYSSL_ERR_X509_KEY_INVALID_VERSION              -0x0240
#define XYSSL_ERR_X509_KEY_INVALID_FORMAT               -0x0260
#define XYSSL_ERR_X509_KEY_INVALID_ENC_IV               -0x0280
#define XYSSL_ERR_X509_KEY_UNKNOWN_ENC_ALG              -0x02A0
#define XYSSL_ERR_X509_KEY_PASSWORD_REQUIRED            -0x02C0
#define XYSSL_ERR_X509_KEY_PASSWORD_MISMATCH            -0x02E0
#define XYSSL_ERR_X509_POINT_ERROR                      -0x0300
#define XYSSL_ERR_X509_VALUE_TO_LENGTH                  -0x0320

#define BADCERT_EXPIRED             0x01  /**< The certificate validity has expired. */
#define BADCERT_REVOKED             0x02  /**< The certificate has been revoked (is on a CRL). */
#define BADCERT_CN_MISMATCH         0x04  /**< The certificate Common Name (CN) does not match with the expected CN. */
#define BADCERT_NOT_TRUSTED         0x08  /**< The certificate is not correctly signed by the trusted CA. */
#define BADCRL_NOT_TRUSTED          0x10  /**< CRL is not correctly signed by the trusted CA. */
#define BADCRL_EXPIRED              0x20  /**< CRL is expired. */
#define BADCERT_MISSING             0x40  /**< Certificate was missing. */
#define BADCERT_SKIP_VERIFY         0x80  /**< Certificate verification was skipped. */

/*
 * DER constants
 */
#define ASN1_BOOLEAN                 0x01
#define ASN1_INTEGER                 0x02
#define ASN1_BIT_STRING              0x03
#define ASN1_OCTET_STRING            0x04
#define ASN1_NULL                    0x05
#define ASN1_OID                     0x06
#define ASN1_UTF8_STRING             0x0C
#define ASN1_SEQUENCE                0x10
#define ASN1_SET                     0x11
#define ASN1_PRINTABLE_STRING        0x13
#define ASN1_T61_STRING              0x14
#define ASN1_IA5_STRING              0x16
#define ASN1_UTC_TIME                0x17
#define ASN1_GENERALIZED_TIME        0x18
#define ASN1_UNIVERSAL_STRING        0x1C
#define ASN1_BMP_STRING              0x1E
#define ASN1_PRIMITIVE               0x00
#define ASN1_CONSTRUCTED             0x20
#define ASN1_CONTEXT_SPECIFIC        0x80

/*
 * various object identifiers
 */
#define X520_COMMON_NAME                3
#define X520_COUNTRY                    6
#define X520_LOCALITY                   7
#define X520_STATE                      8
#define X520_ORGANIZATION              10
#define X520_ORG_UNIT                  11
#define PKCS9_EMAIL                     1

#define X509_OUTPUT_DER              0x01
#define X509_OUTPUT_PEM              0x02
#define PEM_LINE_LENGTH                72
#define X509_ISSUER                  0x01
#define X509_SUBJECT                 0x02

#define OID_X520                "\x55\x04"
#define OID_CN                  "\x55\x04\x03"
#define OID_PKCS1               "\x2A\x86\x48\x86\xF7\x0D\x01\x01"
#define OID_PKCS1_RSA           "\x2A\x86\x48\x86\xF7\x0D\x01\x01\x01"
#define OID_PKCS1_RSA_SHA       "\x2A\x86\x48\x86\xF7\x0D\x01\x01\x05"
#define OID_PKCS9               "\x2A\x86\x48\x86\xF7\x0D\x01\x09"
#define OID_PKCS9_EMAIL         "\x2A\x86\x48\x86\xF7\x0D\x01\x09\x01"

/*
 * Structures for parsing X.509 certificates
 */
typedef struct _x509_buf
{
    int tag;
    int len;
    unsigned char *p;
}
x509_buf;

typedef struct _x509_name
{
    x509_buf oid;
    x509_buf val;
    struct _x509_name *next;
}
x509_name;

typedef struct _x509_time
{
    int year, mon, day;
    int hour, min, sec;
}
x509_time;

typedef struct _x509_cert
{
    x509_buf raw;
    x509_buf tbs;

    int version;
    x509_buf serial;
    x509_buf sig_oid1;

    x509_buf issuer_raw;
    x509_buf subject_raw;

    x509_name issuer;
    x509_name subject;

    x509_time valid_from;
    x509_time valid_to;

    x509_buf pk_oid;
    rsa_context rsa;

    x509_buf issuer_id;
    x509_buf subject_id;
    x509_buf v3_ext;

    int ca_istrue;
    int max_pathlen;

    x509_buf sig_oid2;
    x509_buf sig;

    struct _x509_cert *next; 
}
x509_cert;

/*
 * Structures for writing X.509 certificates
 */
typedef struct _x509_node
{
    unsigned char *data;
    unsigned char *p;
    unsigned char *end;

    size_t len;
}
x509_node;

typedef struct _x509_raw
{
    x509_node raw;
    x509_node tbs;

    x509_node version;
    x509_node serial;
    x509_node tbs_signalg;
    x509_node issuer;
    x509_node validity;
    x509_node subject;
    x509_node subpubkey;

    x509_node signalg;
    x509_node sign;
}
x509_raw;

#ifdef __cplusplus
extern "C" {
#endif

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
int x509parse_crt(void *ssl, x509_cert *crt, unsigned char *buf, int buflen );

/**
 * \brief          Load one or more certificates and add them
 *                 to the chained list
 *
 * \param chain    points to the start of the chain
 * \param path     filename to read the certificates from
 *
 * \return         0 if successful, or a specific X509 error code
 */
int x509parse_crtfile(void *ssl, x509_cert *crt, char *path );

/**
 * \brief          Parse a private RSA key
 *
 * \param rsa      RSA context to be initialized
 * \param buf      input buffer
 * \param buflen   size of the buffer
 * \param pwd      password for decryption (optional)
 * \param pwdlen   size of the password
 *
 * \return         0 if successful, or a specific X509 error code
 */
int x509parse_key(void *ssl, rsa_context *rsa,
                   unsigned char *buf, int buflen,
                   unsigned char *pwd, int pwdlen );

/**
 * \brief          Load and parse a private RSA key
 *
 * \param rsa      RSA context to be initialized
 * \param path     filename to read the private key from
 * \param pwd      password to decrypt the file (can be NULL)
 *
 * \return         0 if successful, or a specific X509 error code
 */
int x509parse_keyfile(void *ssl, rsa_context *rsa, char *path, char *password );

/**
 * \brief          Store the certificate DN in printable form into buf;
 *                 no more than (end - buf) characters will be written.
 */
int x509parse_dn_gets( char *buf, char *end, x509_name *dn );

/**
 * \brief          Returns an informational string about the
 *                 certificate.
 */
char *x509parse_cert_info( char *prefix, x509_cert *crt );

/**
 * \brief          Return 0 if the certificate is still valid,
 *                 or BADCERT_EXPIRED
 */
int x509parse_expired( x509_cert *crt );

/**
 * \brief          Verify the certificate signature
 *
 * \param crt      a certificate to be verified
 * \param trust_ca the trusted CA chain
 * \param cn       expected Common Name (can be set to
 *                 NULL if the CN must not be verified)
 * \param flags    result of the verification
 *
 * \return         0 if successful or XYSSL_ERR_X509_SIG_VERIFY_FAILED,
 *                 in which case *flags will have one or more of
 *                 the following values set:
 *                      BADCERT_EXPIRED --
 *                      BADCERT_REVOKED --
 *                      BADCERT_CN_MISMATCH --
 *                      BADCERT_NOT_TRUSTED
 *
 * \note           TODO: add two arguments, depth and crl
 */
int x509parse_verify(void *ssl, x509_cert *crt,
                      x509_cert *trust_ca,
                      char *cn, int *flags );

/**
 * \brief          Unallocate all certificate data
 */
void x509_free(void *ssl, x509_cert *crt );

/**
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
int x509_self_test(void *ssl, int verbose );

#ifdef __cplusplus
}
#endif

#endif /* x509.h */
