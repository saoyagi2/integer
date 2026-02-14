#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int ac, char *av[] )
{
    int count, i, n, tmp, types[10];
    char buf[1024];

    while( fgets( buf, 1024, stdin ) ) {
        n = (int)strtol( buf, NULL, 10 );

        for( i = 0; i < 10; i++ )
            types[i] = 0;
        tmp = n;
        while( tmp != 0 ) {
            types[tmp % 10]++;
            tmp /= 10;
        }
        count = 0;
        for( i = 0; i < 10; i++ )
            if( types[i] != 0 )
                count++;

        printf( "%d %d\n", n, count );
    }

    return( 0 );
}
