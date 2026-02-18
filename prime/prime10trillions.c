#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIEVE_SIZE_MAX   (100000000)
#define MAX_N (10000000000000)

char    sieve[SIEVE_SIZE_MAX];

int initprimelist( long long **primelist, long long *primelistcount );

int main( void )
{
    long long base, sievesize, p, n, i, j, prev_p;
    long long *primelist, primelistcount;

    /*  序数側の素数一覧を生成  */
    if( !initprimelist( &primelist, &primelistcount ) ) {
        fprintf( stderr, "initprimelist failed\n" );
        return( 1 );
    }

    /*  SIEVE_SIZE_MAX分ごとの整数区間をふるいにかける   */
    prev_p = 0;
    for( base = 2; base < MAX_N; base += SIEVE_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( MAX_N - base + 1 > SIEVE_SIZE_MAX )
            sievesize = SIEVE_SIZE_MAX;
        else
            sievesize = MAX_N - base + 1;

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
            if( sieve[n] == 1 ) {
                /*  前の素数との差分で出力  */
                printf( "%lld\n", base + n - prev_p );
                prev_p = base + n;
            }
        }
    }

    return( 0 );
}

/*  序数側の素数一覧を生成  */
int initprimelist( long long **primelist, long long *primelistcount )
{
    long long n, i;

    /*  ふるいを初期化する    */
    for( n = 2; n * n <= MAX_N; n++ )
        sieve[n] = 1;

    /*  ふるいにかける    */
    for( n = 2; n * n <= MAX_N; n++ ) {
        if( sieve[n] == 1 ) {
            for( i = n * n; i * i <= MAX_N; i+=n )
                sieve[i] = 0;
        }
    }

    /* 素数一覧配列にコピー */
    *primelistcount = 0;
    for( n = 2; n * n <= MAX_N; n++ ) {
        if( sieve[n] == 1 )
            (*primelistcount)++;
    }
    if( ( *primelist = calloc( *primelistcount, sizeof(long long) ) ) == NULL )
        return( 0 );
    for( n = 2, i = 0; n * n <= MAX_N; n++ ) {
        if( sieve[n] == 1 )
            (*primelist)[i++] = n;
    }

    return( 1 );
}
