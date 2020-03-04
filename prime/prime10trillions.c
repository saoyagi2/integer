#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ARRAY   (100000000)
#define MAX_N (10000000000000)
#define START_R (0x40000000)

char    array[MAX_ARRAY];
long long primelistcount;
long long *primelist;

int initprimelist( void );

int main( int ac, char *av[] )
{
    long long base, arraysize, n, i, j, prev;

    /*  序数側の素数一覧を生成  */
    if( !initprimelist() )
        return( 0 );

    prev = 0;
    /*  MAX_ARRAY分ごとの整数区間をふるいにかける   */
    for( base = 2; base < MAX_N; base += MAX_ARRAY ) {
        /*  整数区間配列の大きさを決める    */
        if( MAX_N - base + 1 > MAX_ARRAY )
            arraysize = MAX_ARRAY;
        else
            arraysize = MAX_N - base + 1;

        /*  配列を初期化する    */
        for( i = 0; i < arraysize; i++ )
            array[i] = 1;

        /*  配列をふるいにかける    */
        for( i = 0; i < primelistcount; i++ ) {
            n = primelist[i];
            if( base <= n )
                j = n;
            else if( base % n == 0 )
                j = base;
            else
                j = ( base / n + 1 ) * n;
            j = j < n * n ? n * n : j;
            for( ; j < base + arraysize; j += n )
                array[j - base] = 0;
        }

        /*  ふるいで残った数は素数である    */
        for( n = 0; n < arraysize; n++ ) {
            if( array[n] == 1 ) {
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
    long long n, i, r;
    long long sqrt_llong_max;

    /* sqrt(MAX_N)を求める */
    r = START_R;
    sqrt_llong_max = 0;
    while( r ) {
        if( MAX_N >= ( sqrt_llong_max + r ) * ( sqrt_llong_max + r ) )
            sqrt_llong_max += r;
        r /= 2;
    }

    /*  配列を初期化する    */
    for( i = 0; i <= sqrt_llong_max; i++ )
        array[i] = 1;

    /*  配列をふるいにかける    */
    for( n = 2; n <= sqrt_llong_max; n++ ) {
        if( array[n] == 1 ) {
            for( i = n * n; i <= sqrt_llong_max; i+=n ) {
                array[i] = 0;
            }
        }
    }

    /* 素数一覧配列にコピー */
    primelistcount = 0;
    for( n = 2; n <= sqrt_llong_max; n++ ) {
        if( array[n] == 1 )
            primelistcount++;
    }
    primelist = calloc( primelistcount, sizeof(long long) );
    if( primelist == NULL )
        return( 0 );
    for( n = 2, i = 0; n <= sqrt_llong_max; n++ ) {
        if( array[n] == 1 )
            primelist[i++] = n;
    }

    return( 1 );
}
