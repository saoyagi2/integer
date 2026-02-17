#include <stdio.h>

#define ARRAY_SIZE_MAX   (100000000)
#define LIST_MAX   (100)

int array[ARRAY_SIZE_MAX];

int main( void )
{
    int n, n_list[LIST_MAX], i, j;

    /*  配列を初期化する    */
    for( n = 1; n < ARRAY_SIZE_MAX; n++ )
        array[n] = 0;

    /*  約数の和を求める    */
    for( n = 1; n < ARRAY_SIZE_MAX / 2; n++ ) {
        for( i = 2; i * n < ARRAY_SIZE_MAX; i++ )
            array[i * n] += n;
    }

    /*  約数の和をたどって元の数に戻れば社交数である  */
    for( n = 1; n < ARRAY_SIZE_MAX; n++ ) {
        n_list[0] = n;
        for( i = 1; i < LIST_MAX; i++ ) {
            n_list[i] = array[n_list[i - 1]];
            if( n_list[i] >= ARRAY_SIZE_MAX || n_list[i] < n ) {
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
