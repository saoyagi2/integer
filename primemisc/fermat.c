#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int isprime( mpz_t n );

int main( int ac, char *av[] )
{
    int n;
    mpz_t f, p, tmp, i;

    /*  コマンドラインから指数を決定する    */
    if( ac < 2 )
        return( 1 );
    n = strtol( av[1], NULL, 10 );

    mpz_init( f );
    mpz_init( p );
    mpz_init( i );
    mpz_init( tmp );

    /*  フェルマー数を求める    */
    mpz_set_ui( p, 2 );
    mpz_pow_ui( tmp, p, n );
    mpz_set( p, tmp );

    mpz_set_ui( i, 1 );
    mpz_set_ui( f, 2 );
    while( mpz_cmp( i, p ) < 0 ) {
        mpz_mul_ui( tmp, f, 2 );
        mpz_set( f, tmp );
        mpz_add_ui( tmp, i, 1 );
        mpz_set( i, tmp );
    }
    mpz_add_ui( tmp, f, 1 );
    mpz_set( f, tmp );

    if( isprime( f ) )
        gmp_printf( "%Zd OK\n", f );
    else
        gmp_printf( "%Zd NG\n", f );

    mpz_clear( f );
    mpz_clear( p );
    mpz_clear( i );
    mpz_clear( tmp );

    return( 0 );
}

int isprime( mpz_t n )
{
    mpz_t i, n2, tmp;
    int ret;

    /*  1は素数ではない */
    if( mpz_cmp_ui( n, 1 ) == 0 )
        return( 0 );

    /*  2以外で2で割り切れたら合成数    */
    if( mpz_cmp_ui( n, 2 ) != 0 && mpz_even_p( n ) )
        return( 0 );

    mpz_init( i );
    mpz_init( n2 );
    mpz_init( tmp );

    /*  sqrt(n)+1を求める */
    mpz_sqrt( n2, n );
    mpz_add_ui( tmp, n2, 1 );
    mpz_set( n2, tmp );

    /*  n2以下の奇数での剰余が0かどうか調べる   */
    mpz_set_ui( i, 3 );
    ret = 1;
    while( mpz_cmp( i, n2 ) < 0 ) {
        if( mpz_divisible_p( n, i ) ) {
            ret = 0;
            break;
        }
        mpz_add_ui( tmp, i, 2 );
        mpz_set( i, tmp );
    }

    mpz_clear( i );
    mpz_clear( n2 );
    mpz_clear( tmp );

    return( ret );
}
