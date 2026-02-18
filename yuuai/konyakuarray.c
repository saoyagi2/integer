#include <stdio.h>

#define DIVISORSUMLIST_SIZE_MAX   (100000000)

int divisorsumlist[DIVISORSUMLIST_SIZE_MAX];

int main( void )
{
    int n, n2, i;

    /*  配列を初期化する    */
    for( n = 1; n < DIVISORSUMLIST_SIZE_MAX; n++ )
        divisorsumlist[n] = 0;

    /*  約数の和を求める    */
    for( n = 2; n < DIVISORSUMLIST_SIZE_MAX / 2; n++ ) {
        for( i = 2; i * n < DIVISORSUMLIST_SIZE_MAX; i++ )
            divisorsumlist[i * n] += n;
    }

    /*  約数の和が互いの数自身になれば婚約数である  */
    for( n = 1; n < DIVISORSUMLIST_SIZE_MAX; n++ ) {
        n2 = divisorsumlist[n];
        if( n2 < DIVISORSUMLIST_SIZE_MAX && n < n2 && divisorsumlist[n2] == n )
            printf( "%d %d\n", n, n2 );
    }

    return( 0 );
}
