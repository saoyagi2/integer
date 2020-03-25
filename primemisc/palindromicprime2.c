#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int ac, char *av[] )
{
    long long n, _n, n2, d, p;
    char buf[1024];

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtoll( buf, NULL, 10 );
        n = _n = p + d;
        n2 = 0;
        while( _n != -0 ) {
            n2 = n2 * 10 + _n % 10;
            _n /= 10;
        }
        if( n == n2 )
            printf( "%lld\n", n );
        p = n;
    }

    return( 0 );
}
