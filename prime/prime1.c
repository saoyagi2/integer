#include <stdio.h>
#include <stdlib.h>

#define START_R (0x4000)


int isprime( int n );

int main( int ac, char *av[] )
{
    int n, min_n, max_n;

    /*  コマンドラインから素数探索範囲を決定する    */
    if( ac < 3 )
        return( 1 );
    min_n = strtol( av[1], NULL, 10 );
    max_n = strtol( av[2], NULL, 10 );

    /*  探索範囲の数を調べる    */
    for( n = min_n; n <= max_n; n++ ) {
        if( isprime( n ) )
            printf( "%d\n", n );
    }

    return( 0 );
}

int isprime( int n )
{
    int i, n2, r, d;

    /*  1は素数ではない */
    if( n == 1 )
        return( 0 );

    /*  2,3は素数 */
    if( n == 2 || n == 3 )
        return( 1 );

    /*  2,3で割り切れたら合成数    */
    if( n % 2 == 0 || n % 3 == 0 )
        return( 0 );

    /*  sqrt(n)を求める */
    r = START_R;
    n2 = 0;
    while( r ) {
        if( n >= ( n2 + r ) * ( n2 + r ) )
            n2 += r;
        r /= 2;
    }

    /*  n2以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    for( i = 5; i <= n2; i += d, d = ( d == 2 ? 4 : 2 ) ) {
        if( n % i == 0 )
            return( 0 );
    }

    /*  素数であった    */
    return( 1 );
}
