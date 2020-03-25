#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    long long d, n, p;
    char buf[1024];

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtoll( buf, NULL, 10 );
        n = p + d;
        if( p != 0 && d == 2 )
            printf( "%lld %lld\n", p, n );
        p = n;
    }

    return( 0 );
}
