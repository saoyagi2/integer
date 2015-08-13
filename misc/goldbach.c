#include <stdio.h>
#include <stdlib.h>

#define START_R (0x4000)

int isprime( int n );

int main( int ac, char *av[] )
{
    int n, max_n, m1, m2;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 2 )
        return( 1 );
    max_n = strtol( av[1], NULL, 10 );
    max_n = max_n % 2 == 1 ? max_n + 1 : max_n;

    /*  探索範囲の数を調べる    */
    for( n = 6; n <= max_n; n += 2 ) {
        /*  足してnになる整数組(m1,m2)が共に素数か調べる    */
        for( m1 = 3, m2 = n - 3; m1 <= m2; m1 += 2, m2 -= 2 ) {
            if( isprime( m1 ) && isprime( m2 ) )
                break;
        }
        if( m1 > m2 )
            printf( "%d NG\n", n );
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
