#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define ARRAY_SIZE   (100000000)

mpz_t array[ARRAY_SIZE];

int main( int ac, char *av[] )
{
    int arraysize, i;
    mpz_t base, n, min_n, max_n, to_n, tmp, mpz_i, to_i;

    /*  コマンドラインから完全数探索範囲を決定する    */
    if( ac < 3 )
        return( 1 );
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );

    mpz_init( n );
    mpz_init( tmp );
    mpz_init( to_i );
    mpz_init( to_n );
    mpz_init( mpz_i );

    /*  ARRAY_SIZE分ごとの整数区間を調べる   */
    for( mpz_init_set( base, min_n ); mpz_cmp( base, max_n ) < 0; mpz_add_ui( base, base, ARRAY_SIZE ) ) {
        /*  整数区間配列の大きさを決める    */
        mpz_sub( tmp, max_n, base );
        mpz_add_ui( tmp, tmp, 1 );
        if( mpz_cmp_ui( tmp, ARRAY_SIZE ) > 0 ) {
            arraysize = ARRAY_SIZE;
        }
        else {
            arraysize = mpz_get_ui( tmp );
        }
        /*  配列を初期化する    */
        for( i = 0; i < arraysize; i++ ) {
            mpz_init_set_ui( array[i], 0 );
		}

        /*  約数の和を求める    */
        mpz_add_ui( to_n, base, arraysize );
        mpz_tdiv_q_ui( to_n, to_n, 2 );
        for( mpz_set_ui( n, 1 ); mpz_cmp( n, to_n ) < 0; mpz_add_ui( n, n, 1 ) ) {
            if( mpz_cmp( base, n ) <= 0 ) {
                mpz_mul_ui( mpz_i, n, 2 );
            }
            else if( mpz_mod( tmp, base, n ), mpz_cmp_ui( tmp, 0 ) == 0 ) {
                mpz_set( mpz_i, base );
            }
            else {
                mpz_tdiv_q( mpz_i, base, n );
                mpz_add_ui( mpz_i, mpz_i, 1 );
                mpz_mul( mpz_i, mpz_i, n );
            }
            mpz_add_ui( to_i, base, arraysize );
            for( ; mpz_cmp( mpz_i, to_i ) < 0; mpz_add( mpz_i, mpz_i, n ) ) {
                mpz_sub( tmp, mpz_i, base );
                i = mpz_get_ui( tmp );
                mpz_add( array[i], array[i], n );
            }
        }

        /*  約数の和とその数自身が等しければ完全数である    */
        for( i = 0; i < arraysize; i++ ) {
            mpz_add_ui( tmp, base, i );
            if( mpz_cmp( array[i], tmp ) == 0 )
                gmp_printf( "%Zd\n", tmp );
        }
    }

    return( 0 );
}
