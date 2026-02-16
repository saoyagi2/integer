#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int n, min_n, max_n, sum, i;

    /*  コマンドラインから完全数探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "usage : perfect min_n max_n\n" );
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
        /*  約数の総和を求める  */
        sum = 0;
        for( i = 1; i < n; i++ ) {
            if( n % i == 0 )
                sum += i;
        }

        /*  約数の総和が自身に等しければ完全数である    */
        if( sum == n )
            printf( "%d\n", n );
    }

    return( 0 );
}
