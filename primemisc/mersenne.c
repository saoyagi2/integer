#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main( int ac, char *av[] )
{
    int i, p;
    mpz_t m, s;

    /*  コマンドラインから指数を決定する    */
    if( ac < 2 ) {
        fprintf( stderr, "usage : mersenne p\n" );
        return( 1 );
    }
    p = (int)strtol( av[1], NULL, 10 );
    if( p < 1 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  メルセンヌ数を求める    */
    mpz_init_set_ui( m, 2 );
    mpz_pow_ui( m, m, p );
    mpz_sub_ui( m, m, 1 );

    /*  リュカ-レーマー法で素数判定する */
    mpz_init_set_ui( s, 4 );
    for( i = 2; i <= p - 1; i++ ) {
        mpz_mul( s, s, s );
        mpz_sub_ui( s, s, 2 );
        mpz_mod( s, s, m );
    }
    if( mpz_cmp_ui( s, 0 ) == 0 )
        printf( "OK\n" );
    else
        printf( "NG\n" );

    mpz_clear( m );
    mpz_clear( s );

    return( 0 );
}
