#include <stdio.h>

#define ARRAY_SIZE_MAX   (100000000)

int array[ARRAY_SIZE_MAX];

int main( int ac, char *av[] )
{
    int n, n2, i;

    /*  配列を初期化する    */
    for( i = 0; i < ARRAY_SIZE_MAX; i++ )
        array[i] = 0;

    /*  約数の和を求める    */
    for( n = 1; n < ARRAY_SIZE_MAX / 2; n++ ) {
        for( i = 2; i * n < ARRAY_SIZE_MAX; i++ )
            array[i * n] += n;
    }

    /*  約数の和が互いの数自身になれば友愛数である  */
    for( n = 1; n < ARRAY_SIZE_MAX; n++ ) {
        n2 = array[n];
        if( n2 < ARRAY_SIZE_MAX && n < n2 && array[n2] == n )
            printf( "%d %d\n", n, n2 );
    }

    return( 0 );
}
