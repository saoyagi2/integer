#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int n, min_n, max_n;
    int i, n2, n3;

    /*  コマンドラインから婚約数探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : konyaku min_n max_n\n" );
        return( 1 );
    }
    min_n = strtol( av[1], NULL, 10 );
    max_n = strtol( av[2], NULL, 10 );

    /*  探索範囲の数を調べる    */
    for( n = min_n; n <= max_n; n++ ) {
        n2 = 0;
        for( i = 2; i < n; i++ ) {
            if( n % i == 0 ) {
                n2 += i;
            }
        }
        if( n2 <= n ) {
            continue;
        }

        n3 = 0;
        for( i = 2; i < n2; i++ ) {
            if( n2 % i == 0 ) {
                n3 += i;
            }
        }
        if( n3 == n ) {
            printf( "%d %d\n", n, n2 );
        }
    }

    return( 0 );
}
