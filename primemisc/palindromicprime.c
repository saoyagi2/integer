#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    int n, p, tmp;
    char buf[1024];

    /*  回文素数を探す  */
    while( fgets( buf, 1024, stdin ) ) {
        p = tmp = (int)strtol( buf, NULL, 10 );
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
