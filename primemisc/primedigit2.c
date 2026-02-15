#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    int count, i, types[10];
    long long d, n, tmp, p;
    char buf[1024];

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtoll( buf, NULL, 10 );
        n = p + d;

        for( i = 0; i < 10; i++ )
            types[i] = 0;
        tmp = n;
        while( tmp != 0 ) {
            types[tmp % 10] = 1;
            tmp /= 10;
        }
        count = 0;
        for( i = 0; i < 10; i++ ) {
            if( types[i] != 0 )
                count++;
        }

        printf( "%lld %d\n", n, count );

        p = n;
    }

    return( 0 );
}
