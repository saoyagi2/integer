#include <stdio.h>

#define MAX_ARRAY   (100000000)

int array[MAX_ARRAY];

int main( int ac, char *av[] )
{
    int n, n2, n3, i;

    /*  配列を初期化する    */
    for( i = 0; i < MAX_ARRAY; i++ )
        array[i] = 0;

    /*  約数の和を求める    */
    for( n = 1; n < MAX_ARRAY / 2; n++ ) {
        for( i = 2; i * n < MAX_ARRAY; i++ )
            array[i * n] += n;
    }

    /*  約数の和が互いの数自身になれば友愛数である  */
    for( n = 1; n < MAX_ARRAY; n++ ) {
        n2 = array[n];
        if( n2 >= MAX_ARRAY )
            continue;
        n3 = array[n2];
        if( n3 >= MAX_ARRAY )
            continue;
        if( n < n2 && n < n3 && array[n3] == n )
            printf( "%d %d %d\n", n, n2, n3 );
    }

    return( 0 );
}
