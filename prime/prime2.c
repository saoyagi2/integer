#include <stdio.h>
#include <string.h>

#define SIEVE_SIZE   (100000000)
#define CLEARSIEVE(n) (sieve[(n)>>3] &= (~(1u<<((n) & 7))))
#define SETSIEVE(n) (sieve[(n)>>3] |= (1u<<((n) & 7)))
#define GETSIEVE(n) ((sieve[(n)>>3] & (1u<<((n) & 7))))

unsigned char    sieve[SIEVE_SIZE>>3];

int main( void )
{
    long long n, i;

    /*  ふるいを初期化する    */
    memset( sieve, 0xFF, sizeof(sieve) );

    /*  ふるいにかける    */
    for( n = 2; n < SIEVE_SIZE / n; n++ ) {
        if( GETSIEVE( n ) ) {
            for( i = n * n; i < SIEVE_SIZE; i += n )
                CLEARSIEVE( i );
        }
    }

    /*  ふるいで残った数は素数である    */
    for( n = 2; n < SIEVE_SIZE; n++ ) {
        if( GETSIEVE( n ) )
            printf( "%lld\n", n );
    }

    return( 0 );
}
