#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define MAX_ARRAY   (100000000)
#define MAX_ARRAY_SQRT (10000)

char    array[MAX_ARRAY];

void initarray( void );
int isprime( mpz_t n );

int main( int ac, char *av[] )
{
    mpz_t n, min_n, max_n, m1, m2, tmp;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 )
        return( 1 );
    mpz_init_set_str( min_n, av[1], 10 );
    mpz_init_set_str( max_n, av[2], 10 );
    mpz_init( n );
    mpz_init( m1 );
    mpz_init( m2 );
    mpz_init( tmp );

    initarray();

    /*  探索範囲の数を調べる    */
    mpz_set( n, min_n );
    while( mpz_cmp( n, max_n ) <= 0 ) {
        /*  足してnになる整数組(m1,m2)が共に素数か調べる    */
        mpz_set_ui( m1, 3 );
        mpz_sub_ui( m2, n, 3 );
        while( mpz_cmp( m1, m2 ) <= 0 ) {
            if( isprime( m1 ) && isprime( m2 ) )
                break;
            mpz_add_ui( tmp, m1, 2 );
            mpz_set( m1, tmp );
            mpz_sub_ui( tmp, m2, 2 );
            mpz_set( m2, tmp );
        }
        if( mpz_cmp( m1, m2 ) > 0 )
            gmp_printf( "%Zd NG\n", n );

        mpz_add_ui( tmp, n, 2 );
        mpz_set( n, tmp );
    }

    mpz_clear( max_n );
    mpz_clear( n );
    mpz_clear( m1 );
    mpz_clear( m2 );
    mpz_clear( tmp );

    return( 0 );
}

void initarray( void )
{
    int n, i;

    /*  配列を初期化する    */
    for( i = 0; i < MAX_ARRAY; i++ )
        array[i] = 1;

    /*  配列をふるいにかける    */
    for( n = 2; n <= MAX_ARRAY_SQRT; n++ ) {
        if( array[n] == 1 ) {
            for( i = n * n; i < MAX_ARRAY; i += n )
                array[i] = 0;
        }
    }
}

int isprime( mpz_t n )
{
    mpz_t i, n2, tmp;
    int _n, ret;

    if( mpz_cmp_ui( n, MAX_ARRAY ) < 0 ) {
        _n = mpz_get_ui( n );
        return( array[_n] );
    }

    /*  2割り切れたら合成数    */
    if( mpz_even_p( n ) )
        return( 0 );

    mpz_init( i );
    mpz_init( n2 );
    mpz_init( tmp );

    /*  sqrt(n)を求める */
    mpz_sqrt( n2, n );

    mpz_set_ui( i, MAX_ARRAY + 1 );
    ret = 1;
    while( mpz_cmp( i, n2 ) < 0 ) {
        if( mpz_divisible_p( n, i ) ) {
            ret = 0;
            break;
        }
        mpz_add_ui( tmp, i, 2 );
        mpz_set( i, tmp );
    }

    mpz_clear( i );
    mpz_clear( n2 );
    mpz_clear( tmp );

    return( ret );
}
