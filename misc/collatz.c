#include <gmp.h>

int main( int ac, char *av[] )
{
    mpz_t n, n2, min_n, max_n, tmp;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 )
        return( 1 );
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );

    mpz_init( n );
    mpz_init( n2 );
    mpz_init( tmp );

    /*  探索範囲の数を調べる    */
    mpz_set( n, min_n );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        mpz_set( n2, n );

        /*  n2がn未満になれば計算終了   */
        while( mpz_cmp( n2, n ) >= 0 ) {
            if( mpz_even_p( n2 ) ) {
                /*  偶数なら2で割る */
                mpz_div_ui( tmp, n2, 2 );
                mpz_set( n2, tmp );
            }
            else {
                /*  奇数なら3を掛け1を加え、2で割る    */
                mpz_mul_ui( tmp, n2, 3 );
                mpz_add_ui( n2, tmp, 1 );
                mpz_div_ui( tmp, n2, 2 );
                mpz_set( n2, tmp );
            }
        }

        mpz_add_ui( tmp, n, 2 );
        mpz_set( n, tmp );
    }

    mpz_clear( n );
    mpz_clear( n2 );
    mpz_clear( max_n );
    mpz_clear( tmp );

    return( 0 );
}
