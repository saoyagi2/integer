#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE  (1024)

int main( void )
{
    long long p, prev_p, v;
    char buf[BUF_SIZE];

    /*  双子素数を探す  */
    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        v = strtoll( buf, NULL, 10 );
        if( v == 0 )
            continue;
        p = prev_p + v;
        if( prev_p != 0 && p - prev_p == 2 )
            printf( "%lld %lld\n", prev_p, p );
        prev_p = p;
    }

    return( 0 );
}
