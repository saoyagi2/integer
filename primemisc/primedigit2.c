#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE  (1024)

int main( void )
{
    int count, i, types[10];
    long long p, tmp, prev_p;
    char buf[BUF_SIZE];

    /*  素数の各桁を数える  */
    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
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
