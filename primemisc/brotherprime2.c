#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    long long i, n, *p, d, d2;
    char buf[1024];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 ) {
        fprintf( stderr, "usage : brotherprime2 d2\n" );
        return( 1 );
    }
    d2 = strtoll( av[1], NULL, 10 );
    if( d2 < 2 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    p = calloc( d2, sizeof(int) );
    if( p == NULL ) {
        fprintf( stderr, "calloc failed\n" );
        return( 1 );
    }
    for( i = 0; i < d2; i++ )
        p[i] = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = (int)strtol( buf, NULL, 10 );
        n = p[d2 - 1] + d;
        for( i = 1; i < d2; i++ ) {
            if( p[i] != 0 && n - d2 == p[i] )
                printf( "%lld %lld\n", p[i], n );
        }
        for( i = 1; i < d2; i++ )
            p[i - 1] = p[i];
        p[d2 - 1] = n;
    }

    return( 0 );
}
