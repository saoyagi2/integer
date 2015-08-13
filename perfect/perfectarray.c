#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY   (100000000)

int array[MAX_ARRAY];

int main( int ac, char *av[] )
{
    int base, arraysize, n, max_n, i;

    /*  コマンドラインから完全数探索範囲を決定する    */
    if( ac < 2 )
        return( 1 );
    max_n = strtol( av[1], NULL, 10 );

    /*  MAX_ARRAY分ごとの整数区間を調べる   */
    for( base = 2; base < max_n; base += MAX_ARRAY ) {
        /*  整数区間配列の大きさを決める    */
        if( max_n - base + 1 > MAX_ARRAY )
            arraysize = MAX_ARRAY;
        else
            arraysize = max_n - base + 1;

        /*  配列を初期化する    */
        for( i = 0; i < arraysize; i++ )
            array[i] = 0;

        /*  約数の和を求める    */
        for( n = 1; n < ( base + arraysize ) / 2; n++ ) {
            if( base <= n )
                i = n * 2;
            else if( base % n == 0 )
                i = base;
            else
                i = ( base / n + 1 ) * n;
            for( ; i < base + arraysize; i += n )
                array[i - base] += n;
        }

        /*  約数の和とその数自身が等しければ完全数である    */
        for( n = 0; n < arraysize; n++ ) {
            if( array[n] == base + n )
                printf( "%d\n", base + n );
        }
    }

    return( 0 );
}
