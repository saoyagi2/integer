#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    long long n, p, d, d2;
    char buf[1024];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 ) {
        printf( "usage : brotherprime2 d2\n" );
        return( 1 );
    }
    d2 = strtoll( av[1], NULL, 10 );

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtol( buf, NULL, 10 );
        n = p + d;
        if( p != 0 && d == d2 )
            printf( "%lld %lld\n", p, n );
        p = n;
    }

    return( 0 );
}
