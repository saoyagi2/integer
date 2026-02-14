#include <stdio.h>
#include <stdlib.h>

int isprime( int n );
int isqrt( int x );

int main( int ac, char *av[] )
{
    int n, min_n, max_n, m1, m2;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : goldbach min_n max_n\n" );
        return( 1 );
    }
    min_n = (int)strtol( av[1], NULL, 10 );
    min_n = min_n % 2 == 1 ? min_n + 1 : min_n;
    max_n = (int)strtol( av[2], NULL, 10 );
    max_n = max_n % 2 == 1 ? max_n + 1 : max_n;

    /*  探索範囲の数を調べる    */
    for( n = min_n; n <= max_n; n += 2 ) {
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
    int i, n2, d;

    /*  1以下は素数ではない */
    if( n <= 1 )
        return( 0 );

    /*  2,3は素数 */
    if( n == 2 || n == 3 )
        return( 1 );

    /*  2,3で割り切れたら合成数    */
    if( n % 2 == 0 || n % 3 == 0 )
        return( 0 );

    /*  sqrt(n)を求める */
    n2 = isqrt( n );

    /*  n2以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    for( i = 5; i <= n2; i += d, d = ( d == 2 ? 4 : 2 ) ) {
        if( n % i == 0 )
            return( 0 );
    }

    /*  素数であった    */
    return( 1 );
}

int isqrt( int x )
{
    int s, t;

    if( x == 0 ) return 0;
    s = 1;
    t = x;
    while( s < t ) {
        s <<= 1;
        t >>= 1;
    }
    do {
        t = s;
        s = ( x / s + s ) >> 1;
    } while( s < t );

    return( t );
}
