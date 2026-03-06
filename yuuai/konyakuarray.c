#include <stdio.h>
#include <stdlib.h>

#define DIVISORSUMLIST_SIZE_MAX   (100000000)

long long divisorsumlist[DIVISORSUMLIST_SIZE_MAX];

int main( int ac, char *av[] )
{
    long long divisorsumlistsize, i, j, base, n, n2, tmp, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "usage : yuuai min_n max_n\n" );
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
        for( i = 2; i <= ( base + divisorsumlistsize ) / 2; i++ ) {
            j = ( base + i - 1 ) / i * i;
            if( j < i * 2 )
                j = i * 2;
            for( ; j < base + divisorsumlistsize; j += i )
                divisorsumlist[j - base] += i;
        }

        /*  約数の和が互いの数自身になれば婚約数である  */
        for( i = 0; i < divisorsumlistsize; i++ ) {
            n = base + i;
            n2 = divisorsumlist[i];
            if( n2 < base + divisorsumlistsize ) {
                if( n < n2 && divisorsumlist[n2 - base] == n )
                    printf( "%lld %lld\n", n, n2 );
            }
            else {
                /*  配列の範囲外の場合は個別計算する  */
                tmp = 0;
                for( j = 2; j <= n2 / 2; j++ ) {
                    if( n2 % j == 0 )
                        tmp += j;
                }
                if( n == tmp )
                    printf( "%lld %lld\n", n, n2 );
            }
        }
    }

    return( 0 );
}
