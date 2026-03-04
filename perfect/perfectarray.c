#include <stdio.h>
#include <stdlib.h>

#define DIVISORSUMLIST_SIZE_MAX   (100000000)

long long divisorsumlist[DIVISORSUMLIST_SIZE_MAX];

int main( int ac, char *av[] )
{
    long long divisorsumlistsize, i, j, base, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "usage : perfectarray min_n max_n\n" );
        return( 1 );
    }
    min_n = strtoll( av[1], NULL, 10 );
    max_n = strtoll( av[2], NULL, 10 );
    if( min_n < 1 || max_n < 1 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  DIVISORSUMLIST_SIZE_MAX分ごとの整数区間を調べる   */
    for( base = min_n; base <= max_n; base += DIVISORSUMLIST_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( max_n - base + 1 > DIVISORSUMLIST_SIZE_MAX )
            divisorsumlistsize = DIVISORSUMLIST_SIZE_MAX;
        else
            divisorsumlistsize = max_n - base + 1;

        /*  配列を初期化する    */
        for( i = 0; i < divisorsumlistsize; i++ )
            divisorsumlist[i] = 0;

        /*  約数の和を求める    */
        for( i = 1; i < ( base + divisorsumlistsize ) / 2; i++ ) {
            j = ( base + i - 1 ) / i * i;
            if( j < i * 2 )
                j = i * 2;
            for( ; j < base + divisorsumlistsize; j += i )
                divisorsumlist[j - base] += i;
        }

        /*  約数の和とその数自身が等しければ完全数である    */
        for( i = 0; i < divisorsumlistsize; i++ ) {
            if( divisorsumlist[i] == base + i )
                printf( "%lld\n", base + i );
        }
    }

    return( 0 );
}
