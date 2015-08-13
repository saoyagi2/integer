#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int LucasLehmerTest( mpz_t n, int p );

int main( int ac, char *av[] )
{
    int p;
    mpz_t m, tmp;

    /*  コマンドラインから指数を決定する    */
    if( ac < 2 )
        return( 1 );
    p = strtol( av[1], NULL, 10 );

    /*  メルセンヌ数を求める    */
    mpz_init_set_ui( m, 2 );
    mpz_init( tmp );
    mpz_pow_ui( tmp, m, p );
    mpz_set( m, tmp );
    mpz_sub_ui( tmp, m, 1 );
    mpz_set( m, tmp );

    if( LucasLehmerTest( m, p ) )
        gmp_printf( "%Zd OK\n", m );
    else
        gmp_printf( "%Zd NG\n", m );

    mpz_clear( m );
    mpz_clear( tmp );

    return( 0 );
}

int LucasLehmerTest( mpz_t n, int p )
{
    int i, ret;
    mpz_t s, tmp;

    mpz_init_set_ui( s, 4 );
    mpz_init( tmp );
    for( i = 2; i <= p - 1; i++ ) {
        mpz_mul( tmp, s, s );
        mpz_sub_ui( s, tmp, 2 );
        mpz_mod( tmp, s, n );
        mpz_set( s, tmp );
    }
    ret = ( mpz_cmp_ui( s, 0 ) == 0 );

    mpz_clear( s );
    mpz_clear( tmp );

    return( ret );
}
