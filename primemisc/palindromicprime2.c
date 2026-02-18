#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    long long n, p, tmp, prev_p;
    char buf[1024];

    /*  回文素数を探す  */
    prev_p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        p = tmp = prev_p + strtoll( buf, NULL, 10 );
        n = 0;
        while( tmp != 0 ) {
            n = n * 10 + tmp % 10;
            tmp /= 10;
        }
        if( p == n )
            printf( "%lld\n", p );
        prev_p = n;
    }

    return( 0 );
}
