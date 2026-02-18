#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    int count, i, types[10];
    long long p, tmp, prev_p;
    char buf[1024];

    /*  素数の各桁を数える  */
    prev_p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        p = prev_p + strtoll( buf, NULL, 10 );

        for( i = 0; i < 10; i++ )
            types[i] = 0;
        tmp = p;
        while( tmp != 0 ) {
            types[tmp % 10] = 1;
            tmp /= 10;
        }
        count = 0;
        for( i = 0; i < 10; i++ ) {
            if( types[i] != 0 )
                count++;
        }

        printf( "%lld %d\n", p, count );

        prev_p = p;
    }

    return( 0 );
}
