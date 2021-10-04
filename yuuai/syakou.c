#include <stdio.h>
#include <stdlib.h>

#define LIST_MAX   (100)

int main( int ac, char *av[] )
{
    int n, min_n, max_n;
    int n_list[LIST_MAX], i, j;

    /*  コマンドラインから社交数探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : syakou min_n max_n\n" );
        return( 1 );
    }
    min_n = strtol( av[1], NULL, 10 );
    max_n = strtol( av[2], NULL, 10 );

    /*  探索範囲の数を調べる    */
    for( n = min_n; n <= max_n; n++ ) {
        n_list[0] = n;
        for( i = 1; i < LIST_MAX; i++ ) {
            n_list[i] = 0;
            for( j = 1; j <= n_list[i - 1] / 2; j++ ) {
                if( n_list[i - 1] % j == 0 ) {
                    n_list[i] += j;
                }
            }
            if( n_list[i] < n ) {
                break;
            }
            if( n_list[i] == n_list[0] ) {
                if( i > 2 ) {
                    for( j = 0; j < i; j++ ) {
                        printf( "%d ", n_list[j] );
                    }
                    printf( "\n" );
                }
                break;
            }
        }
    }

    return( 0 );
}
