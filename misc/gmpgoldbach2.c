#include <stdio.h>
#include <gmp.h>

#define SIEVE_SIZE   (100000000)

char    sieve[SIEVE_SIZE];

void initsieve( void );
int isprime( const mpz_t n );

int main( int ac, char *av[] )
{
    mpz_t n, min_n, max_n, m1, m2;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : gmpgoldbach2 min_n max_n\n" );
        return( 1 );
    }
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );
    if( mpz_init_set_str( min_n, av[1], 10 ) == -1
        || mpz_cmp_ui( min_n, 6 ) < 0
        || mpz_init_set_str( max_n, av[2], 10 ) == -1
        || mpz_cmp_ui( max_n, 6 ) < 0 ) {
        printf( "bad parameter\n" );
        return( 1 );
    }

    initsieve();

    /*  探索範囲の数を調べる    */
    mpz_init_set( n, min_n );
    mpz_init( m1 );
    mpz_init( m2 );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        /*  足してnになる整数組(m1,m2)が共に素数か調べる    */
        mpz_set_ui( m1, 3 );
        mpz_sub_ui( m2, n, 3 );
        while( mpz_cmp( m1, m2 ) <= 0 ) {
            if( isprime( m1 ) && isprime( m2 ) )
                break;
            mpz_add_ui( m1, m1, 2 );
            mpz_sub_ui( m2, m2, 2 );
        }
        if( mpz_cmp( m1, m2 ) > 0 )
            gmp_printf( "%Zd NG\n", n );

        mpz_add_ui( n, n, 2 );
    }

    mpz_clear( min_n );
    mpz_clear( max_n );
    mpz_clear( n );
    mpz_clear( m1 );
    mpz_clear( m2 );

    return( 0 );
}

void initsieve( void )
{
    int n, i;

    /*  ふるいを初期化する    */
    for( n = 2; n < SIEVE_SIZE; n++ )
        sieve[n] = 1;

    /*  ふるいにかける    */
    for( n = 2; n * n <= SIEVE_SIZE; n++ ) {
        if( sieve[n] == 1 ) {
            for( i = n * n; i < SIEVE_SIZE; i += n )
                sieve[i] = 0;
        }
    }
}

int isprime( const mpz_t n )
{
    mpz_t i, tmp;
    int d, ret;

    /*  1以下は素数ではない */
    if( mpz_cmp_si( n, 1 ) <= 0 )
        return( 0 );

    /*  ふるいの範囲内ならふるいを使用して素数判定  */
    if( mpz_cmp_ui( n, SIEVE_SIZE ) < 0 )
        return( sieve[mpz_get_ui( n )] );

    /*  2,3で割り切れたら合成数    */
    if( mpz_even_p( n ) || mpz_divisible_ui_p( n, 3 ) )
        return( 0 );

    /*  n2以下の2,3の倍数以外での剰余が0かどうか調べる   */
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
