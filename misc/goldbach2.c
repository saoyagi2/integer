#include <stdio.h>
#include <stdlib.h>

#define SIEVE_SIZE   (100000000)

char    sieve[SIEVE_SIZE];

void initsieve( void );
int isprime( int n );

int main( int ac, char *av[] )
{
    int n, min_n, max_n, m1, m2;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : goldbach2 min_n max_n\n" );
        return( 1 );
    }
    min_n = (int)strtol( av[1], NULL, 10 );
    max_n = (int)strtol( av[2], NULL, 10 );
    if( min_n < 6 || max_n < 6 ) {
        printf( "bad parameter\n" );
        return( 1 );
    }

    initsieve();

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

void initsieve( void )
{
    int n, i;

    /*  ふるいを初期化する    */
    for( n = 2; n < SIEVE_SIZE; n++ )
        sieve[n] = 1;

    /*  ふるいにかける    */
    for( n = 2; n * n <= SIEVE_SIZE; n++ ) {
        if( sieve[n] == 1 ) {
            for( i = n * n; i < SIEVE_SIZE; i += n )
                sieve[i] = 0;
        }
    }
}

int isprime( int n )
{
    int i, d;

    /*  1以下は素数ではない */
    if( n <= 1 )
        return( 0 );

    /*  ふるいの範囲内ならふるいを使用して素数判定  */
    if( n < SIEVE_SIZE )
        return( sieve[n] );

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
