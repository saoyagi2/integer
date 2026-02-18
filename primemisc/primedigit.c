#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE  (1024)

int main( void )
{
    int count, i, p, tmp, types[10];
    char buf[BUF_SIZE];

    /*  素数の各桁を数える  */
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        p = (int)strtol( buf, NULL, 10 );

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

        printf( "%d %d\n", p, count );
    }

    return( 0 );
}
