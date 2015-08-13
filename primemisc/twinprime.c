#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    long long  n, m;
    char buf[1024];

    m = -1;
    while( fgets( buf, 1024, stdin ) ) {
        n = strtoll( buf, NULL, 10 );
        if( m != -1 && n - 2 == m )
            printf( "%lld %lld\n", m, n );
        m = n;
    }

    return( 0 );
}
