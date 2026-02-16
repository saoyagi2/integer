#include <stdio.h>
#include <stdlib.h>

int isprime( int n );

int main( int ac, char *av[] )
{
    int n, min_n, max_n;

    /*  コマンドラインから素数探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "prime1 min_n max_n\n" );
        return( 1 );
    }
    min_n = (int)strtol( av[1], NULL, 10 );
    max_n = (int)strtol( av[2], NULL, 10 );
    if( min_n < 2 || max_n < 2 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  探索範囲の数を調べる    */
    for( n = min_n; n <= max_n; n++ ) {
        if( isprime( n ) )
            printf( "%d\n", n );
    }

    return( 0 );
}

int isprime( int n )
{
    int i, d;

    /*  1以下は素数ではない */
    if( n <= 1 )
        return( 0 );

    /*  2,3は素数 */
    if( n == 2 || n == 3 )
        return( 1 );

    /*  2,3で割り切れたら合成数    */
    if( n % 2 == 0 || n % 3 == 0 )
        return( 0 );

    /*  自乗がn以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    for( i = 5; i * i <= n; i += d, d = ( d == 2 ? 4 : 2 ) ) {
        if( n % i == 0 )
            return( 0 );
    }

    /*  素数であった    */
    return( 1 );
}
