#include <stdio.h>
#include <gmp.h>

int main( int ac, char *av[] )
{
    mpz_t n, n2, tmp, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : collatz min_n max_n\n" );
        return( 1 );
    }
    if( mpz_init_set_str( min_n, av[1], 10 ) == -1
        || mpz_cmp_ui( min_n, 1 ) < 0
        || mpz_init_set_str( max_n, av[2], 10 ) == -1
        || mpz_cmp_ui( max_n, 1 ) < 0 ) {
        printf( "bad parameter\n" );
        return( 1 );
    }

    mpz_init_set( n, min_n );
    mpz_init( tmp );
    mpz_init( n2 );

    /*  n を 4n+3 に揃える  */
    mpz_tdiv_r_ui( tmp, n, 4 );
    mpz_add_ui( n, n, 3 - mpz_get_ui( tmp ) );

    /*  探索範囲の数を調べる    */
    while( mpz_cmp( n, max_n ) <= 0 ) {
        /*  n2がn未満になれば計算終了   */
        mpz_set( n2, n );
        while( mpz_cmp( n2, n ) >= 0 ) {
            if( mpz_even_p( n2 ) ) {
                /*  偶数なら2で割る */
                mpz_tdiv_q_ui( n2, n2, 2 );
            }
            else {
                /*  奇数なら3を掛け1を加え、2で割る    */
                mpz_mul_ui( n2, n2, 3 );
                mpz_add_ui( n2, n2, 1 );
                mpz_tdiv_q_ui( n2, n2, 2 );
            }
        }

        mpz_add_ui( n, n, 4 );
    }

    mpz_clear( n );
    mpz_clear( n2 );
    mpz_clear( tmp );
    mpz_clear( min_n );
    mpz_clear( max_n );

    return( 0 );
}
