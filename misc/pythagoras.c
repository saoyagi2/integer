#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int a, b, c, aa, bb, cc, max_n;

    /*  コマンドラインからピタゴラス探索範囲を決定する  */
    if( ac < 2 )
        return( 1 );
    max_n = strtol( av[1], NULL, 10 );

    /*  探索範囲の数を調べる    */
    for( c = 1; c < max_n; c++ ) {
        cc = c * c;
        for( b = 1; b < c; b++ ) {
            bb = b * b;
            for( a = 1; a < b; a++ ) {
                aa = a * a;
                if( aa + bb == cc )
                    printf( "%d %d %d\n", a, b, c );
            }
        }
    }

    return( 0 );
}
