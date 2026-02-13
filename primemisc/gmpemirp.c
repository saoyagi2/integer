#include <stdio.h>
#include <gmp.h>

int isprime( mpz_t n );

int main( int ac, char *av[] )
{
    int m;
    mpz_t n, _n, n2, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : gmpemirp min_n max_n\n" );
        return( 1 );
    }
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );

    /*  探索範囲の数を調べる    */
    mpz_init( _n );
    mpz_init( n2 );
    for( mpz_init_set( n, min_n ); mpz_cmp( n, max_n ) <= 0; mpz_add_ui( n, n, 1 ) ) {
        /* nが素数でなかったら次へ */
        if( !isprime( n ) )
            continue;
        /*  逆から読んだ数字が素数か調べる    */
        mpz_set( _n, n );
        mpz_set_ui( n2, 0 );
        while( mpz_cmp_ui( _n, 0 ) != 0 ) {
            mpz_mul_ui( n2, n2, 10 );
            m = mpz_fdiv_q_ui( _n, _n, 10 );
            mpz_add_ui( n2, n2, m );
        }
        /* 元の数と同じ場合はエマープではない */
        if( mpz_cmp( n, n2 ) == 0 )
            continue;
        if( isprime( n2 ) )
            gmp_printf( "%Zd\n", n );
    }

    mpz_clear( n );
    mpz_clear( _n );
    mpz_clear( n2 );
    mpz_clear( min_n );
    mpz_clear( max_n );

    return( 0 );
}

int isprime( mpz_t n )
{
    mpz_t i, n2;
    int d, ret;

    /*  1は素数ではない */
    if( mpz_cmp_ui( n, 1 ) == 0 )
        return( 0 );

    /*  2,3は素数 */
    if( mpz_cmp_ui( n, 2 ) == 0 || mpz_cmp_ui( n, 3 ) == 0 )
        return( 1 );

    /*  2,3で割り切れたら合成数    */
    if( mpz_even_p( n ) || mpz_divisible_ui_p( n, 3 ) )
        return( 0 );

    /*  sqrt(n)を求める */
    mpz_init( n2 );
    mpz_sqrt( n2, n );

    /*  n2以下の2,3の倍数以外での剰余が0かどうか調べる   */
    d = 2;
    mpz_init_set_ui( i, 5 );
    ret = 1;
    while( mpz_cmp( i, n2 ) <= 0 ) {
        if( mpz_divisible_p( n, i ) ) {
            ret = 0;
            break;
        }
        mpz_add_ui( i, i, d );
        d = ( d == 2 ? 4 : 2 );
    }

    mpz_clear( i );
    mpz_clear( n2 );

    return( ret );
}
