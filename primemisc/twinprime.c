#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int n, p;
    char buf[1024];

    p = -1;
    while( fgets( buf, 1024, stdin ) ) {
        n = (int)strtol( buf, NULL, 10 );
        if( p != -1 && n - 2 == p )
            printf( "%d %d\n", p, n );
        p = n;
    }

    return( 0 );
}
