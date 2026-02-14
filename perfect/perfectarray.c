#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE_MAX   (100000000)

int array[ARRAY_SIZE_MAX];

int main( int ac, char *av[] )
{
    int base, arraysize, min_n, max_n, i, j;

    /*  コマンドラインから完全数探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : perfectarray min_n max_n\n" );
        return( 1 );
    }
    min_n = (int)strtol( av[1], NULL, 10 );
    max_n = (int)strtol( av[2], NULL, 10 );

    /*  ARRAY_SIZE_MAX分ごとの整数区間を調べる   */
    for( base = min_n; base < max_n; base += ARRAY_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( max_n - base + 1 > ARRAY_SIZE_MAX )
            arraysize = ARRAY_SIZE_MAX;
        else
            arraysize = max_n - base + 1;

        /*  配列を初期化する    */
        for( i = 0; i < arraysize; i++ )
            array[i] = 0;

        /*  約数の和を求める    */
        for( i = 1; i < ( base + arraysize ) / 2; i++ ) {
            if( base <= i )
                j = i * 2;
            else if( base % i == 0 )
                j = base;
            else
                j = ( base / i + 1 ) * i;
            for( ; j < base + arraysize; j += i )
                array[j - base] += i;
        }

        /*  約数の和とその数自身が等しければ完全数である    */
        for( i = 0; i < arraysize; i++ ) {
            if( array[i] == base + i )
                printf( "%d\n", base + i );
        }
    }

    return( 0 );
}
