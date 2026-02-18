#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE  (1024)

int main( void )
{
    int p, prev_p;
    char buf[BUF_SIZE];

    /*  双子素数を探す  */
    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        p = (int)strtol( buf, NULL, 10 );
        if( p == 0 )
            continue;
        if( prev_p != 0 && p - prev_p == 2 )
            printf( "%d %d\n", prev_p, p );
        prev_p = p;
    }

    return( 0 );
}
