#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int isprime( mpz_t n );

int main( int ac, char *av[] )
{
    int   a, b, c;
    mpz_t n, n2, max_n, tmp;

    /*  コマンドラインから係数と探索範囲を決定する    */
    if( ac < 5 ) {
        printf( "usage : primegen a b c max_n\n" );
        return( 1 );
    }
    a = strtol( av[1], NULL, 10 );
    b = strtol( av[2], NULL, 10 );
    c = strtol( av[3], NULL, 10 );
    mpz_init_set_str( max_n, av[4], 10 );

    /*  探索範囲の数を調べる    */
    mpz_init_set_ui( n, 0 );
    mpz_init( n2 );
    mpz_init( tmp );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        /*  a * n^2 + b * n + c を求める   */
        mpz_mul( n2, n, n );
        mpz_mul_ui( n2, n2, a );
        mpz_mul_ui( tmp, n, b );
        mpz_add( n2, n2, tmp );
        mpz_add_ui( n2, n2, c );

        /*  素数かどうか調べる  */
        if( isprime( n2 ) )
            gmp_printf( "%Zd %Zd OK\n", n, n2 );
        else
            gmp_printf( "%Zd %Zd NG\n", n, n2 );

        mpz_add_ui( n, n, 1 );
    }

    mpz_clear( n );
    mpz_clear( n2 );
    mpz_clear( max_n );
    mpz_clear( tmp );

    return( 0 );
}

int isprime( mpz_t n )
{
    mpz_t i, n2;
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

    /*  sqrt(n)を求める */
    mpz_init( n2 );
    mpz_sqrt( n2, n );

    /*  n2以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    mpz_init_set_ui( i, 5 );
    ret = 1;
    while( mpz_cmp( i, n2 ) <= 0 ) {
        if( mpz_divisible_p( n, i ) ) {
            ret = 0;
            break;
        }
        mpz_add_ui( i, i, d );
        d = ( d == 2 ? 4 : 2 );
    }

    mpz_clear( i );
    mpz_clear( n2 );

    return( ret );
}
