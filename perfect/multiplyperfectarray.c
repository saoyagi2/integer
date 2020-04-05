#include <stdio.h>
#include <stdlib.h>

#define    ARRAY_SIZE    (100000000)

int array[ARRAY_SIZE];

int main( int ac, char *av[] )
{
    int base, arraysize, m, min_n, max_n, i, j;

    /*  コマンドラインからm及び探索範囲を決定する    */
    if( ac < 4 )
        return( 1 );
    m = strtol( av[1], NULL, 10 );
    min_n = strtol( av[2], NULL, 10 );
    max_n = strtol( av[3], NULL, 10 );

    /*    ARRAY_SIZE分ごとの整数区間を調べる    */
    for( base = min_n; base < max_n; base += ARRAY_SIZE ) {
        /*    整数区間配列の大きさを決める    */
        if( max_n - base + 1 > ARRAY_SIZE )
            arraysize = ARRAY_SIZE;
        else
            arraysize = max_n - base + 1;

        /*    配列を初期化する    */
        for( i = 0; i < arraysize; i++ )
            array[i] = 0;

        /*    約数の和を求める    */
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

        /*    約数の和とその数自身のm倍が等しければ倍積完全数である    */
        for( i = 0; i < arraysize; i++ ) {
            if( array[i] == m * ( base + i ) )
                printf( "%d\n", base + i );
        }
    }

    return( 0 );
}