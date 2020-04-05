#include <stdio.h>
#include <stdlib.h>

#define    ARRAY_SIZE    (100000000)

int array[ARRAY_SIZE];

int main( int ac, char *av[] )
{
    int base, arraysize, m, n, min_n, max_n, i;

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

        /*    約数の和とその数自身のm倍が等しければ倍積完全数である    */
        for( n = 0; n < arraysize; n++ ) {
            if( array[n] == m * ( base + n ) )
                printf( "%d\n", base + n );
        }
    }

    return( 0 );
}
