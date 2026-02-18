#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE  (1024)

int main( void )
{
    int n, p, tmp;
    char buf[BUF_SIZE];

    /*  回文素数を探す  */
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        p = tmp = (int)strtol( buf, NULL, 10 );
        if( p == 0 )
            continue;
        n = 0;
        while( tmp != 0 ) {
            n = n * 10 + tmp % 10;
            tmp /= 10;
        }
        if( p == n )
            printf( "%d\n", p );
    }

    return( 0 );
}
