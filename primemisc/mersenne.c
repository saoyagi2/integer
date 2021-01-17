#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int LucasLehmerTest( mpz_t n, int p );

int main( int ac, char *av[] )
{
    int p;
    mpz_t m;

    /*  コマンドラインから指数を決定する    */
    if( ac < 2 ) {
        printf( "usage : mersenne p\n" );
        return( 1 );
    }
    p = strtol( av[1], NULL, 10 );

    /*  メルセンヌ数を求める    */
    mpz_init_set_ui( m, 2 );
    mpz_pow_ui( m, m, p );
    mpz_sub_ui( m, m, 1 );

    if( LucasLehmerTest( m, p ) )
        printf( "OK\n" );
    else
        printf( "NG\n" );

    mpz_clear( m );

    return( 0 );
}

int LucasLehmerTest( mpz_t m, int p )
{
    int i, ret;
    mpz_t s;

    mpz_init_set_ui( s, 4 );
    for( i = 2; i <= p - 1; i++ ) {
        mpz_mul( s, s, s );
        mpz_sub_ui( s, s, 2 );
        mpz_mod( s, s, m );
    }
    ret = ( mpz_cmp_ui( s, 0 ) == 0 );

    mpz_clear( s );

    return( ret );
}
