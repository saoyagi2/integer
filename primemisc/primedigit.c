#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    int count, i, p, tmp, types[10];
    char buf[1024];

    /*  素数の各桁を数える  */
    while( fgets( buf, 1024, stdin ) ) {
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
