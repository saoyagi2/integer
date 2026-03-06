#include <stdio.h>
#include <stdlib.h>

#define DIVISORSUMLIST_SIZE_MAX   (100000000)
#define LIST_MAX   (100)

long long divisorsumlist[DIVISORSUMLIST_SIZE_MAX];

int main( int ac, char *av[] )
{
    long long divisorsumlistsize, i, j, k, base, n_list[LIST_MAX], min_n, max_n;

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
        for( i = 1; i <= ( base + divisorsumlistsize ) / 2; i++ ) {
            j = ( base + i - 1 ) / i * i;
            if( j < i * 2 )
                j = i * 2;
            for( ; j < base + divisorsumlistsize; j += i )
                divisorsumlist[j - base] += i;
        }

        /*  約数の和をたどって元の数に戻れば社交数である  */
        for( i = 0; i < divisorsumlistsize; i++ ) {
            n_list[0] = base + i;
            for( j = 1; j < LIST_MAX; j++ ) {
                if( n_list[j - 1] < base + divisorsumlistsize ) {
                    n_list[j] = divisorsumlist[n_list[j - 1] - base];
                }
                else {
                    /*  配列の範囲外の場合は個別計算する  */
                    n_list[j] = 0;
                    for( k = 1; k <= n_list[j - 1] / 2; k++ ) {
                        if( n_list[j - 1] % k == 0 )
                            n_list[j] += k;
                    }
                }
                if( n_list[j] < n_list[0] )
                    break;
                if( n_list[j] == n_list[0] ) {
                    if( j > 2 ) {
                        for( k = 0; k < j; k++ )
                            printf( "%lld ", n_list[k] );
                        printf( "\n" );
                    }
                    break;
                }
            }
        }
    }

    return( 0 );
}
