#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countdigit( int n );

int main( int ac, char *av[] )
{
    int count, n;
    char buf[1024];

    while( fgets( buf, 1024, stdin ) ) {
        n = strtol( buf, NULL, 10 );
        count = countdigit( n );
        printf( "%d %d\n", n, count );
    }

    return( 0 );
}


int countdigit( int n )
{
    int     i, types[10], count;
    char    buf[1024];

    for( i = 0; i < 10; i++ )
        types[i] = 0;

    sprintf( buf, "%d", n );
    for( i = 0; i < strlen( buf ); i++ )
        types[buf[i] - '0']++;

    count = 0;
    for( i = 0; i < 10; i++ )
        if( types[i] != 0 )
            count++;

    return( count );
}
