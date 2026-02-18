#include <stdio.h>
#include <gmp.h>

int isprime( const mpz_t n );

int main( int ac, char *av[] )
{
    int m;
    mpz_t n, n2, tmp, min_n, max_n;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "usage : emirp min_n max_n\n" );
        return( 1 );
    }
    if( mpz_init_set_str( min_n, av[1], 10 ) == -1
        || mpz_cmp_ui( min_n, 2 ) < 0
        || mpz_init_set_str( max_n, av[2], 10 ) == -1
        || mpz_cmp_ui( max_n, 2 ) < 0 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  探索範囲の数を調べる    */
    mpz_init( tmp );
    mpz_init( n2 );
    mpz_init_set( n, min_n );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        /* nが素数でなかったら次へ */
        if( !isprime( n ) ) {
            mpz_add_ui( n, n, 1 );
            continue;
        }
        /*  逆から読んだ数字が素数か調べる    */
        mpz_set( tmp, n );
        mpz_set_ui( n2, 0 );
        while( mpz_cmp_ui( tmp, 0 ) != 0 ) {
            mpz_mul_ui( n2, n2, 10 );
            m = mpz_fdiv_q_ui( tmp, tmp, 10 );
            mpz_add_ui( n2, n2, m );
        }
        /* 元の数と同じ場合はエマープではない */
        if( mpz_cmp( n, n2 ) == 0 ) {
            mpz_add_ui( n, n, 1 );
            continue;
        }
        if( isprime( n2 ) )
            gmp_printf( "%Zd\n", n );

        mpz_add_ui( n, n, 1 );
    }

    mpz_clear( n );
    mpz_clear( n2 );
    mpz_clear( tmp );
    mpz_clear( min_n );
    mpz_clear( max_n );

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
