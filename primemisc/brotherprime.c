#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int n, p, d;
    char buf[1024];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 ) {
        printf( "usage : brotherprime d\n" );
        return( 1 );
    }
    d = strtol( av[1], NULL, 10 );

    p = -1;
    while( fgets( buf, 1024, stdin ) ) {
        n = strtol( buf, NULL, 10 );
        if( p != -1 && n - d == p )
            printf( "%d %d\n", p, n );
        p = n;
    }

    return( 0 );
}
