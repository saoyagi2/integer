#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int isprime( mpz_t n );

int main( int ac, char *av[] )
{
    mpz_t n, tmp, min_n, max_n;

    /*  コマンドラインから素数探索範囲を決定する    */
    if( ac < 3 )
        return( 1 );
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );
    mpz_init( n );
    mpz_init( tmp );

    /*  探索範囲の数を調べる    */
    mpz_set( n, min_n );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        if( isprime( n ) )
            gmp_printf( "%Zd\n", n );
        mpz_add_ui( tmp, n, 1 );
        mpz_set( n, tmp );
    }

    mpz_clear( n );
    mpz_clear( tmp );
    mpz_clear( max_n );

    return( 0 );
}

int isprime( mpz_t n )
{
    mpz_t i, n2, tmp;
    int d, ret;

    /*  1は素数ではない */
    if( mpz_cmp_ui( n, 1 ) == 0 )
        return( 0 );

    /*  2,3は素数 */
    if( mpz_cmp_ui( n, 2 ) == 0 || mpz_cmp_ui( n, 3 ) == 0 )
        return( 1 );

    /*  2,3で割り切れたら合成数    */
    if( mpz_even_p( n ) || mpz_divisible_ui_p( n, 3 ) )
        return( 0 );

    mpz_init( i );
    mpz_init( n2 );
    mpz_init( tmp );

    /*  sqrt(n)+1を求める */
    mpz_sqrt( n2, n );

    /*  n2以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    mpz_set_ui( i, 5 );
    ret = 1;
    while( mpz_cmp( i, n2 ) <= 0 ) {
        if( mpz_divisible_p( n, i ) ) {
            ret = 0;
            break;
        }
        mpz_add_ui( tmp, i, d );
        mpz_set( i, tmp );
        d = ( d == 2 ? 4 : 2 );
    }

    mpz_clear( i );
    mpz_clear( n2 );
    mpz_clear( tmp );

    return( ret );
}
