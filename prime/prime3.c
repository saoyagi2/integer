#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIEVE_SIZE_MAX   (100000000)

char    sieve[SIEVE_SIZE_MAX];
int primelistcount;
int *primelist;

int initprimelist( int max_n );
int isqrt( int x );

int main( int ac, char *av[] )
{
    int base, sievesize, p, n, min_n, max_n, i, j;

    /*  コマンドラインから素数探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : prime3 min_n max_n\n" );
        return( 1 );
    }
    min_n = (int)strtol( av[1], NULL, 10 );
    max_n = (int)strtol( av[2], NULL, 10 );

    if( !initprimelist( max_n ) )
        return( 0 );

    /*  SIEVE_SIZE_MAX分ごとの整数区間をふるいにかける   */
    for( base = min_n; base < max_n; base += SIEVE_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( max_n - base + 1 > SIEVE_SIZE_MAX )
            sievesize = SIEVE_SIZE_MAX;
        else
            sievesize = max_n - base + 1;

        /*  ふるいを初期化する    */
        for( n = 0; n < sievesize; n++ )
            sieve[n] = 1;

        /*  ふるいにかける    */
        for( i = 0; i < primelistcount; i++ ) {
            p = primelist[i];
            if( p * p >= base + sievesize )
                break;

            if( base <= p )
                j = p;
            else if( base % p == 0 )
                j = base;
            else
                j = ( base / p + 1 ) * p;
            j = j < p * p ? p * p : j;
            for( ; j < base + sievesize; j += p )
                sieve[j - base] = 0;
        }

        /*  ふるいで残った数は素数である    */
        for( n = 0; n < sievesize; n++ ) {
            if( sieve[n] == 1 )
                printf( "%d\n", base + n );
        }
    }

    return( 0 );
}

/*  序数側の素数一覧を生成  */
int initprimelist( int max_n )
{
    int n, i, sqrt_max_n;

    /* sqrt(max_n)を求める */
    sqrt_max_n = isqrt( max_n );

    /*  ふるいを初期化する    */
    for( n = 2; n <= sqrt_max_n; n++ )
        sieve[n] = 1;

    /*  ふるいにかける    */
    for( n = 2; n <= sqrt_max_n; n++ ) {
        if( sieve[n] == 1 ) {
            for( i = n * n; i <= sqrt_max_n; i+=n ) {
                sieve[i] = 0;
            }
        }
    }

    /* 素数一覧配列にコピー */
    primelistcount = 0;
    for( n = 2; n <= sqrt_max_n; n++ ) {
        if( sieve[n] == 1 )
            primelistcount++;
    }
    primelist = calloc( primelistcount, sizeof(int) );
    if( primelist == NULL )
        return( 0 );
    for( n = 2, i = 0; n <= sqrt_max_n; n++ ) {
        if( sieve[n] == 1 )
            primelist[i++] = n;
    }

    return( 1 );
}

int isqrt( int x )
{
    int s, t;

    if( x == 0 ) return 0;
    s = 1;
    t = x;
    while( s < t ) {
        s <<= 1;
        t >>= 1;
    }
    do {
        t = s;
        s = ( x / s + s ) >> 1;
    } while( s < t );

    return( t );
}
