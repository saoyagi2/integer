#include <stdio.h>
#include <gmp.h>

int main( int ac, char *av[] )
{
    mpz_t n, n2, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : collatz min_n max_n\n" );
        return( 1 );
    }
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );

    /*  探索範囲の数を調べる    */
    mpz_init_set( n, min_n );
    mpz_init( n2 );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        mpz_set( n2, n );

        /*  n2が1になれば計算終了   */
        while( mpz_cmp_ui( n2, 1 ) != 0 ) {
            if( mpz_even_p( n2 ) ) {
                /*  偶数なら2で割る */
                mpz_div_ui( n2, n2, 2 );
            }
            else {
                /*  奇数なら3を掛け1を加える    */
                mpz_mul_ui( n2, n2, 3 );
                mpz_add_ui( n2, n2, 1 );
            }
        }

        mpz_add_ui( n, n, 1 );
    }

    mpz_clear( n );
    mpz_clear( n2 );
    mpz_clear( max_n );

    return( 0 );
}
