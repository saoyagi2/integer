#include <stdio.h>

#define DIVISORSUMLIST_SIZE_MAX   (100000000)
#define LIST_MAX   (100)

int divisorsumlist[DIVISORSUMLIST_SIZE_MAX];

int main( void )
{
    int n, n_list[LIST_MAX], i, j;

    /*  配列を初期化する    */
    for( n = 1; n < DIVISORSUMLIST_SIZE_MAX; n++ )
        divisorsumlist[n] = 0;

    /*  約数の和を求める    */
    for( n = 1; n < DIVISORSUMLIST_SIZE_MAX / 2; n++ ) {
        for( i = 2; i * n < DIVISORSUMLIST_SIZE_MAX; i++ )
            divisorsumlist[i * n] += n;
    }

    /*  約数の和をたどって元の数に戻れば社交数である  */
    for( n = 1; n < DIVISORSUMLIST_SIZE_MAX; n++ ) {
        n_list[0] = n;
        for( i = 1; i < LIST_MAX; i++ ) {
            n_list[i] = divisorsumlist[n_list[i - 1]];
            if( n_list[i] >= DIVISORSUMLIST_SIZE_MAX || n_list[i] < n )
                break;
            if( n_list[i] == n_list[0] ) {
                if( i > 2 ) {
                    for( j = 0; j < i; j++ )
                        printf( "%d ", n_list[j] );
                    printf( "\n" );
                }
                break;
            }
        }
    }

    return( 0 );
}
