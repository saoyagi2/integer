#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int isprime( const mpz_t n );

int main( int ac, char *av[] )
{
    int n;
    mpz_t f, p, i;

    /*  コマンドラインから指数を決定する    */
    if( ac < 2 ) {
        fprintf( stderr, "usage : fermat n\n" );
        return( 1 );
    }
    n = (int)strtol( av[1], NULL, 10 );

    /*  フェルマー数を求める    */
    mpz_init_set_ui( p, 2 );
    mpz_pow_ui( p, p, n );

    mpz_init_set_ui( i, 1 );
    mpz_init_set_ui( f, 2 );
    while( mpz_cmp( i, p ) < 0 ) {
        mpz_mul_ui( f, f, 2 );
        mpz_add_ui( i, i, 1 );
    }
    mpz_add_ui( f, f, 1 );

    if( isprime( f ) )
        printf( "OK\n" );
    else
        printf( "NG\n" );

    mpz_clear( f );
    mpz_clear( p );
    mpz_clear( i );

    return( 0 );
}

int isprime( const mpz_t n )
{
    mpz_t i, tmp;
    int d, ret;

    /*  1以下は素数ではない */
    if( mpz_cmp_si( n, 1 ) <= 0 )
        return( 0 );

    /*  2,3は素数 */
    if( mpz_cmp_ui( n, 2 ) == 0 || mpz_cmp_ui( n, 3 ) == 0 )
        return( 1 );

    /*  2,3で割り切れたら合成数    */
    if( mpz_even_p( n ) || mpz_divisible_ui_p( n, 3 ) )
        return( 0 );

    /*  自乗がn以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    mpz_init_set_ui( i, 5 );
    mpz_init( tmp );
    ret = 1;
    while( 1 ) {
        mpz_mul( tmp, i, i );
        if( mpz_cmp( tmp, n ) > 0 )
            break;

        if( mpz_divisible_p( n, i ) ) {
            ret = 0;
            break;
        }
        mpz_add_ui( i, i, d );
        d = ( d == 2 ? 4 : 2 );
    }

    mpz_clear( i );
    mpz_clear( tmp );

    return( ret );
}
