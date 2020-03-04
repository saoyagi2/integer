#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int d, n, p;
    char buf[1024];

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtol( buf, NULL, 10 );
        n = p + d;
        if( p != 0 && d == 2 )
            printf( "%d %d\n", p, n );
        p = n;
    }

    return( 0 );
}
