#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int i, n, n2, tmp, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "usage : yuuai min_n max_n\n" );
        return( 1 );
    }
    min_n = (int)strtol( av[1], NULL, 10 );
    max_n = (int)strtol( av[2], NULL, 10 );
    if( min_n < 1 || max_n < 1 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  探索範囲の数を調べる    */
    for( n = min_n; n <= max_n; n++ ) {
        n2 = 0;
        for( i = 1; i <= n / 2; i++ ) {
            if( n % i == 0 )
                n2 += i;
        }
        if( n2 <= n )
            continue;

        tmp = 0;
        for( i = 1; i <= n2 / 2; i++ ) {
            if( n2 % i == 0 )
                tmp += i;
        }
        if( n == tmp )
            printf( "%d %d\n", n, n2 );
    }

    return( 0 );
}
