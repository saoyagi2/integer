#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIEVE_SIZE_MAX   (100000000)
#define MAX_N (10000000000000)

char    sieve[SIEVE_SIZE_MAX];
long long primelistcount;
long long *primelist;

int initprimelist( void );
long long isqrt( long long x );

int main( int ac, char *av[] )
{
    long long base, sievesize, p, n, i, j, prev;

    /*  序数側の素数一覧を生成  */
    if( !initprimelist() )
        return( 0 );

    prev = 0;
    /*  SIEVE_SIZE_MAX分ごとの整数区間をふるいにかける   */
    for( base = 2; base < MAX_N; base += SIEVE_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( MAX_N - base + 1 > SIEVE_SIZE_MAX )
            sievesize = SIEVE_SIZE_MAX;
        else
            sievesize = MAX_N - base + 1;

        /*  ふるいを初期化する    */
        for( i = 0; i < sievesize; i++ )
            sieve[i] = 1;

        /*  ふるいにかける    */
        for( i = 0; i < primelistcount; i++ ) {
            p = primelist[i];
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
                printf( "%lld\n", base + n - prev );
                prev = base + n;
            }
        }
    }

    return( 0 );
}

/*  序数側の素数一覧を生成  */
int initprimelist( void )
{
    long long n, i, sqrt_max_n;

    /* sqrt(MAX_N)を求める */
    sqrt_max_n = isqrt( MAX_N );

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
    primelist = calloc( primelistcount, sizeof(long long) );
    if( primelist == NULL )
        return( 0 );
    for( n = 2, i = 0; n <= sqrt_max_n; n++ ) {
        if( sieve[n] == 1 )
            primelist[i++] = n;
    }

    return( 1 );
}

long long isqrt( long long x )
{
    long long s, t;

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
