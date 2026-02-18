#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    long long p, prev_p;
    char buf[1024];

    /*  双子素数を探す  */
    prev_p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        p = prev_p + strtoll( buf, NULL, 10 );
        if( prev_p != 0 && p - 2 == prev_p )
            printf( "%lld %lld\n", prev_p, p );
        prev_p = p;
    }

    return( 0 );
}
