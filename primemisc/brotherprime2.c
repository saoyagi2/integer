#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    long long n, p, d, d2;
    char buf[1024];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 )
        return( 1 );
    d2 = strtoll( av[1], NULL, 10 );

    p = 0;
    while( fgets( buf, 1024, stdin ) ) {
        d = strtoll( buf, NULL, 10 );
        n = p + d;
        if( p != 0 && d == d2 )
            printf( "%qd %qd\n", p, n );
        p = n;
    }

    return( 0 );
}
