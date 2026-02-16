#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int i, n, *p, d;
    char buf[1024];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 ) {
        fprintf( stderr, "usage : brotherprime d\n" );
        return( 1 );
    }
    d = (int)strtol( av[1], NULL, 10 );
    if( d < 2 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    p = calloc( d, sizeof(int) );
    if( p == NULL ) {
        fprintf( stderr, "calloc failed\n" );
        return( 1 );
    }
    for( i = 0; i < d; i++ )
        p[i] = -1;
    while( fgets( buf, 1024, stdin ) ) {
        n = (int)strtol( buf, NULL, 10 );
        for( i = 0; i < d; i++ ) {
            if( p[i] != -1 && n - d == p[i] )
                printf( "%d %d\n", p[i], n );
        }
        for( i = 1; i < d; i++ )
            p[i - 1] = p[i];
        p[d - 1] = n;
    }

    return( 0 );
}
