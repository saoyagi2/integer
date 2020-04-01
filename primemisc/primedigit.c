#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countdigit( int n );

int main( int ac, char *av[] )
{
    int count, i, n, _n, types[10];
    char buf[1024];

    while( fgets( buf, 1024, stdin ) ) {
        n = strtol( buf, NULL, 10 );

        for( i = 0; i < 10; i++ )
            types[i] = 0;
        _n = n;
        while( _n != 0 ) {
            types[_n % 10]++;
            _n /= 10;
        }
        count = 0;
        for( i = 0; i < 10; i++ )
            if( types[i] != 0 )
                count++;

        printf( "%d %d\n", n, count );
    }

    return( 0 );
}
