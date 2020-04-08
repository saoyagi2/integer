#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define ARRAY_SIZE_MAX   (100000000)

mpz_t array[ARRAY_SIZE_MAX];

int main( int ac, char *av[] )
{
    int arraysize, i, j;
    mpz_t base, min_n, max_n, to_n, tmp, mpz_i, mpz_j, to_i, to_j;

    /*  コマンドラインから完全数探索範囲を決定する    */
    if( ac < 3 )
        return( 1 );
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );

    mpz_init( tmp );
    mpz_init( mpz_i );
    mpz_init( mpz_j );
    mpz_init( to_i );
    mpz_init( to_j );
    mpz_init( to_n );
    for( i = 0; i < ARRAY_SIZE_MAX; i++ ) {
        mpz_init( array[i] );
    }

    /*  ARRAY_SIZE_MAX分ごとの整数区間を調べる   */
    for( mpz_init_set( base, min_n ); mpz_cmp( base, max_n ) < 0; mpz_add_ui( base, base, ARRAY_SIZE_MAX ) ) {
        /*  整数区間配列の大きさを決める    */
        mpz_sub( tmp, max_n, base );
        mpz_add_ui( tmp, tmp, 1 );
        if( mpz_cmp_ui( tmp, ARRAY_SIZE_MAX ) > 0 ) {
            arraysize = ARRAY_SIZE_MAX;
        }
        else {
            arraysize = mpz_get_ui( tmp );
        }
        /*  配列を初期化する    */
        for( i = 0; i < arraysize; i++ ) {
            mpz_set_ui( array[i], 0 );
        }

        /*  約数の和を求める    */
        mpz_add_ui( to_i, base, arraysize );
        mpz_tdiv_q_ui( to_i, to_i, 2 );
        for( mpz_set_ui( mpz_i, 1 ); mpz_cmp( mpz_i, to_i ) < 0; mpz_add_ui( mpz_i, mpz_i, 1 ) ) {
            if( mpz_cmp( base, mpz_i ) <= 0 ) {
                mpz_mul_ui( mpz_j, mpz_i, 2 );
            }
            else if( mpz_mod( tmp, base, mpz_i ), mpz_cmp_ui( tmp, 0 ) == 0 ) {
                mpz_set( mpz_j, base );
            }
            else {
                mpz_tdiv_q( mpz_j, base, mpz_i );
                mpz_add_ui( mpz_j, mpz_j, 1 );
                mpz_mul( mpz_j, mpz_j, mpz_i );
            }
            mpz_add_ui( to_j, base, arraysize );
            for( ; mpz_cmp( mpz_j, to_j ) < 0; mpz_add( mpz_j, mpz_j, mpz_i ) ) {
                mpz_sub( tmp, mpz_j, base );
                j = mpz_get_ui( tmp );
                mpz_add( array[j], array[j], mpz_i );
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
