#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int ac, char *av[] )
{
    int n, _n, n2;
    char buf[1024];

    while( fgets( buf, 1024, stdin ) ) {
        n = _n = strtol( buf, NULL, 10 );
        n2 = 0;
        while( _n != -0 ) {
            n2 = n2 * 10 + _n % 10;
            _n /= 10;
        }
        if( n == n2 )
            printf( "%d\n", n );
    }

    return( 0 );
}
