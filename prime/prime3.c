#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIEVE_SIZE_MAX   (100000000)
#define CLEARSIEVE(n) (sieve[(n)>>3] &= (~(1u<<((n) & 7))))
#define SETSIEVE(n) (sieve[(n)>>3] |= (1u<<((n) & 7)))
#define GETSIEVE(n) ((sieve[(n)>>3] & (1u<<((n) & 7))))

unsigned char sieve[SIEVE_SIZE_MAX>>3];

int initprimelist( long long max_n, long long **primelist, long long *primelistcount );

int main( int ac, char *av[] )
{
    long long base, sievesize, p, n, min_n, max_n, i, j;
    long long *primelist, primelistcount;

    /*  コマンドラインから探索範囲を決定する    */
    if( ac < 3 ) {
        fprintf( stderr, "usage : prime3 min_n max_n\n" );
        return( 1 );
    }
    min_n = strtoll( av[1], NULL, 10 );
    max_n = strtoll( av[2], NULL, 10 );
    if( min_n < 2 || max_n < 2 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  序数側の素数一覧を生成  */
    if( !initprimelist( max_n, &primelist, &primelistcount ) ) {
        fprintf( stderr, "initprimelist failed\n" );
        return( 1 );
    }

    /*  SIEVE_SIZE_MAX分ごとの整数区間をふるいにかける   */
    for( base = min_n; base <= max_n; base += SIEVE_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( max_n - base + 1 > SIEVE_SIZE_MAX )
            sievesize = SIEVE_SIZE_MAX;
        else
            sievesize = max_n - base + 1;

        /*  ふるいを初期化する    */
        memset( sieve, 0xFF, sizeof(sieve) );

        /*  ふるいにかける    */
        for( i = 0; i < primelistcount; i++ ) {
            p = primelist[i];
            if( p * p >= base + sievesize )
                break;

            j = ( base + p - 1 ) / p * p;
            if( j < p * p )
                j = p * p;
            for( ; j < base + sievesize; j += p )
                CLEARSIEVE( j - base );
        }

        /*  ふるいで残った数は素数である    */
        for( n = 0; n < sievesize; n++ ) {
            if( GETSIEVE( n ) )
                printf( "%lld\n", base + n );
        }
    }

    free( primelist );

    return( 0 );
}

/*  序数側の素数一覧を生成  */
int initprimelist( long long max_n, long long **primelist, long long *primelistcount )
{
    long long n, i;

    /*  ふるいを初期化する    */
    memset( sieve, 0xFF, sizeof(sieve) );

    /*  ふるいにかける    */
    for( n = 2; n <= max_n / n; n++ ) {
        if( GETSIEVE( n ) ) {
            for( i = n * n; i < max_n / i; i += n )
                CLEARSIEVE( i );
        }
    }

    /* 素数一覧配列にコピー */
    *primelistcount = 0;
    for( n = 2; n <= max_n / n; n++ ) {
        if( GETSIEVE( n ) )
            (*primelistcount)++;
    }
    if( ( *primelist = calloc( *primelistcount, sizeof(int) ) ) == NULL )
        return( 0 );
    for( n = 2, i = 0; n <= max_n / n; n++ ) {
        if( GETSIEVE( n ) )
            (*primelist)[i++] = n;
    }

    return( 1 );
}
