#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE  (1024)

int main( void )
{
    long long n, p, tmp, prev_p, v;
    char buf[BUF_SIZE];

    /*  回文素数を探す  */
    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        v = strtoll( buf, NULL, 10 );
        if( v == 0 )
            continue;
        p = tmp = prev_p + v;
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
