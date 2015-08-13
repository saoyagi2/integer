#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int n, max_n, sum, i;

    /*  コマンドラインから完全数探索範囲を決定する    */
    if( ac < 2 )
        return( 1 );
    max_n = strtol( av[1], NULL, 10 );

    /*  探索範囲の数を調べる    */
    for( n = 2; n <= max_n; n++ ) {
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
