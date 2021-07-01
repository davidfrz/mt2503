/**
 * \file bignum.h
 */
#ifndef XYSSL_BIGNUM_H
#define XYSSL_BIGNUM_H

#include <stdio.h>
#include "xyssl_fs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"


#define XYSSL_ERR_MPI_FILE_IO_ERROR                     -0x0002
#define XYSSL_ERR_MPI_BAD_INPUT_DATA                    -0x0004
#define XYSSL_ERR_MPI_INVALID_CHARACTER                 -0x0006
#define XYSSL_ERR_MPI_BUFFER_TOO_SMALL                  -0x0008
#define XYSSL_ERR_MPI_NEGATIVE_VALUE                    -0x000A
#define XYSSL_ERR_MPI_DIVISION_BY_ZERO                  -0x000C
#define XYSSL_ERR_MPI_NOT_ACCEPTABLE                    -0x000E

#define MPI_CHK(f) if( ( ret = f ) != 0 ) goto cleanup

/*
 * Define the base integer type, architecture-wise
 */
typedef unsigned long t_int; 
typedef unsigned long long t_dbl;

//typedef unsigned int t_int; 
//typedef unsigned int t_dbl;


/**
 * \brief          MPI structure
 */
typedef struct
{
    int s;              /*!<  integer sign      */
    int n;              /*!<  total # of limbs  */
    t_int *p;           /*!<  pointer to limbs  */
}
mpi;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief          Initialize one or more mpi
 */
void mpi_init( mpi *X, ... );

/**
 * \brief          Unallocate one or more mpi
 */
void mpi_free(void *ssl, mpi *X, ... );

/**
 * \brief          Enlarge to the specified number of limbs
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_grow(void *ssl, mpi *X, int nblimbs );

/**
 * \brief          Copy the contents of Y into X
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_copy(void *ssl, mpi *X, mpi *Y );

/**
 * \brief          Swap the contents of X and Y
 */
void mpi_swap( mpi *X, mpi *Y );

/**
 * \brief          Set value from integer
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_lset(void *ssl, mpi *X, int z );

/**
 * \brief          Return the number of least significant bits
 */
int mpi_lsb( mpi *X );

/**
 * \brief          Return the number of most significant bits
 */
int mpi_msb( mpi *X );

/**
 * \brief          Return the total size in bytes
 */
int mpi_size( mpi *X );

/**
 * \brief          Import from an ASCII string
 *
 * \param X        destination mpi
 * \param radix    input numeric base
 * \param s        null-terminated string buffer
 *
 * \return         0 if successful, or an XYSSL_ERR_MPI_XXX error code
 */
int mpi_read_string(void *ssl, mpi *X, int radix, char *s );

/**
 * \brief          Export into an ASCII string
 *
 * \param X        source mpi
 * \param radix    output numeric base
 * \param s        string buffer
 * \param slen     string buffer size
 *
 * \return         0 if successful, or an XYSSL_ERR_MPI_XXX error code
 *
 * \note           Call this function with *slen = 0 to obtain the
 *                 minimum required buffer size in *slen.
 */
int mpi_write_string(void *ssl, mpi *X, int radix, char *s, int *slen );

/**
 * \brief          Read X from an opened file
 *
 * \param X        destination mpi
 * \param radix    input numeric base
 * \param fin      input file handle
 *
 * \return         0 if successful, or an XYSSL_ERR_MPI_XXX error code
 */
int mpi_read_file(void *ssl, mpi *X, int radix, FS_HANDLE fin );

/**
 * \brief          Write X into an opened file, or stdout
 *
 * \param p        prefix, can be NULL
 * \param X        source mpi
 * \param radix    output numeric base
 * \param fout     output file handle
 *
 * \return         0 if successful, or an XYSSL_ERR_MPI_XXX error code
 *
 * \note           Set fout == NULL to print X on the console.
 */
int mpi_write_file(void *ssl, char *p, mpi *X, int radix, FS_HANDLE fout );

/**
 * \brief          Import X from unsigned binary data, big endian
 *
 * \param X        destination mpi
 * \param buf      input buffer
 * \param buflen   input buffer size
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_read_binary(void *ssl, mpi *X, unsigned char *buf, int buflen );

/**
 * \brief          Export X into unsigned binary data, big endian
 *
 * \param X        source mpi
 * \param buf      output buffer
 * \param buflen   output buffer size
 *
 * \return         0 if successful,
 *                 XYSSL_ERR_MPI_BUFFER_TOO_SMALL if buf isn't large enough
 *
 * \note           Call this function with *buflen = 0 to obtain the
 *                 minimum required buffer size in *buflen.
 */
int mpi_write_binary( mpi *X, unsigned char *buf, int buflen );

/**
 * \brief          Left-shift: X <<= count
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_shift_l(void *ssl, mpi *X, int count );

/**
 * \brief          Right-shift: X >>= count
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_shift_r(void *ssl, mpi *X, int count );

/**
 * \brief          Compare unsigned values
 *
 * \return         1 if |X| is greater than |Y|,
 *                -1 if |X| is lesser  than |Y| or
 *                 0 if |X| is equal to |Y|
 */
int mpi_cmp_abs( mpi *X, mpi *Y );

/**
 * \brief          Compare signed values
 *
 * \return         1 if X is greater than Y,
 *                -1 if X is lesser  than Y or
 *                 0 if X is equal to Y
 */
int mpi_cmp_mpi( mpi *X, mpi *Y );

/**
 * \brief          Compare signed values
 *
 * \return         1 if X is greater than z,
 *                -1 if X is lesser  than z or
 *                 0 if X is equal to z
 */
int mpi_cmp_int( mpi *X, int z );

/**
 * \brief          Unsigned addition: X = |A| + |B|
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_add_abs(void *ssl, mpi *X, mpi *A, mpi *B );

/**
 * \brief          Unsigned substraction: X = |A| - |B|
 *
 * \return         0 if successful,
 *                 XYSSL_ERR_MPI_NEGATIVE_VALUE if B is greater than A
 */
int mpi_sub_abs(void *ssl, mpi *X, mpi *A, mpi *B );

/**
 * \brief          Signed addition: X = A + B
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_add_mpi(void *ssl, mpi *X, mpi *A, mpi *B );

/**
 * \brief          Signed substraction: X = A - B
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_sub_mpi(void *ssl, mpi *X, mpi *A, mpi *B );

/**
 * \brief          Signed addition: X = A + b
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_add_int(void *ssl, mpi *X, mpi *A, int b );

/**
 * \brief          Signed substraction: X = A - b
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_sub_int(void *ssl, mpi *X, mpi *A, int b );

/**
 * \brief          Baseline multiplication: X = A * B
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_mul_mpi(void *ssl, mpi *X, mpi *A, mpi *B );

/**
 * \brief          Baseline multiplication: X = A * b
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_mul_int(void *ssl, mpi *X, mpi *A, t_int b );

/**
 * \brief          Division by mpi: A = Q * B + R
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_DIVISION_BY_ZERO if B == 0
 *
 * \note           Either Q or R can be NULL.
 */
int mpi_div_mpi(void *ssl, mpi *Q, mpi *R, mpi *A, mpi *B );

/**
 * \brief          Division by int: A = Q * b + R
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_DIVISION_BY_ZERO if b == 0
 *
 * \note           Either Q or R can be NULL.
 */
int mpi_div_int(void *ssl, mpi *Q, mpi *R, mpi *A, int b );

/**
 * \brief          Modulo: R = A mod B
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_DIVISION_BY_ZERO if B == 0
 */
int mpi_mod_mpi(void *ssl, mpi *R, mpi *A, mpi *B );

/**
 * \brief          Modulo: r = A mod b
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_DIVISION_BY_ZERO if b == 0
 */
int mpi_mod_int( t_int *r, mpi *A, int b );

/**
 * \brief          Sliding-window exponentiation: X = A^E mod N
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_BAD_INPUT_DATA if N is negative or even
 *
 * \note           _RR is used to avoid re-computing R*R mod N across
 *                 multiple calls, which speeds up things a bit. It can
 *                 be set to NULL if the extra performance is unneeded.
 */
int mpi_exp_mod(void *ssl, mpi *X, mpi *A, mpi *E, mpi *N, mpi *_RR );

/**
 * \brief          Greatest common divisor: G = gcd(A, B)
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed
 */
int mpi_gcd(void *ssl, mpi *G, mpi *A, mpi *B );

/**
 * \brief          Modular inverse: X = A^-1 mod N
 *
 * \return         0 if successful,
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_BAD_INPUT_DATA if N is negative or nil
 *                 XYSSL_ERR_MPI_NOT_ACCEPTABLE if A has no inverse mod N
 */
int mpi_inv_mod(void *ssl, mpi *X, mpi *A, mpi *N );

/**
 * \brief          Miller-Rabin primality test
 *
 * \return         0 if successful (probably prime),
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_NOT_ACCEPTABLE if X is not prime
 */
int mpi_is_prime(void *ssl, mpi *X, int (*f_rng)(void *), void *p_rng );

/**
 * \brief          Prime number generation
 *
 * \param X        destination mpi
 * \param nbits    required size of X in bits
 * \param dh_flag  if 1, then (X-1)/2 will be prime too
 * \param f_rng    RNG function
 * \param p_rng    RNG parameter
 *
 * \return         0 if successful (probably prime),
 *                 1 if memory allocation failed,
 *                 XYSSL_ERR_MPI_BAD_INPUT_DATA if nbits is < 3
 */
int mpi_gen_prime(void *ssl, mpi *X, int nbits, int dh_flag,
                   int (*f_rng)(void *), void *p_rng );

/**
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
int mpi_self_test(void *ssl, int verbose );

#ifdef __cplusplus
}
#endif

#endif /* bignum.h */
