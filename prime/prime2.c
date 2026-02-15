#include <stdio.h>

#define SIEVE_SIZE   (100000000)

char    sieve[SIEVE_SIZE];

int main( void )
{
    int n, i;

    /*  ふるいを初期化する    */
    for( n = 2; n < SIEVE_SIZE; n++ )
        sieve[n] = 1;

    /*  ふるいにかける    */
    for( n = 2; n * n <= SIEVE_SIZE; n++ ) {
        if( sieve[n] == 1 ) {
            for( i = n * n; i < SIEVE_SIZE; i += n )
                sieve[i] = 0;
        }
    }

    /*  ふるいで残った数は素数である    */
    for( n = 2; n < SIEVE_SIZE; n++ ) {
        if( sieve[n] == 1 )
            printf( "%d\n", n );
    }

    return( 0 );
}
