#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE  (1024)

int main( void )
{
    long long p, p2, tmp, prev_p, v;
    char buf[BUF_SIZE];

    /*  回文素数を探す  */
    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        if( ( v = strtoll( buf, NULL, 10 ) ) == 0 )
            continue;
        p = tmp = prev_p + v;
        p2 = 0;
        while( tmp != 0 ) {
            p2 = p2 * 10 + tmp % 10;
            tmp /= 10;
        }
        if( p == p2 )
            printf( "%lld\n", p );
        prev_p = p;
    }

    return( 0 );
}
