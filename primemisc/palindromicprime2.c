#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    long long n, tmp, n2, d, p;
    char buf[1024];

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtoll( buf, NULL, 10 );
        n = tmp = p + d;
        n2 = 0;
        while( tmp != 0 ) {
            n2 = n2 * 10 + tmp % 10;
            tmp /= 10;
        }
        if( n == n2 )
            printf( "%lld\n", n );
        p = n;
    }

    return( 0 );
}
