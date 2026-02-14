#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAY_SIZE_MAX   (100000000)

char    array[ARRAY_SIZE_MAX];
int primelistcount;
int *primelist;

int initprimelist( void );
int isqrt( int x );

int main( int ac, char *av[] )
{
    int base, arraysize, n, min_n, max_n, i, j;

    /*  コマンドラインから素数探索範囲を決定する    */
    if( ac < 3 ) {
        printf( "usage : prime3 min_n max_n\n" );
        return( 1 );
    }
    min_n = strtol( av[1], NULL, 10 );
    max_n = strtol( av[2], NULL, 10 );

    if( !initprimelist() )
        return( 0 );

    /*  ARRAY_SIZE_MAX分ごとの整数区間をふるいにかける   */
    for( base = min_n; base < max_n; base += ARRAY_SIZE_MAX ) {
        /*  整数区間配列の大きさを決める    */
        if( max_n - base + 1 > ARRAY_SIZE_MAX )
            arraysize = ARRAY_SIZE_MAX;
        else
            arraysize = max_n - base + 1;

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
            if( array[n] == 1 )
                printf( "%d\n", base + n );
        }
    }

    return( 0 );
}

int initprimelist( void )
{
    int n, i;
    int sqrt_int_max;

    /* sqrt(INT_MAX)を求める */
    sqrt_int_max = isqrt( INT_MAX );

    /*  配列を初期化する    */
    for( i = 2; i <= sqrt_int_max; i++ )
        array[i] = 1;

    /*  配列をふるいにかける    */
    for( n = 2; n <= sqrt_int_max; n++ ) {
        if( array[n] == 1 ) {
            for( i = n * n; i <= sqrt_int_max; i+=n ) {
                array[i] = 0;
            }
        }
    }

    /* 素数一覧配列にコピー */
    primelistcount = 0;
    for( n = 2; n <= sqrt_int_max; n++ ) {
        if( array[n] == 1 )
            primelistcount++;
    }
    primelist = calloc( primelistcount, sizeof(int) );
    if( primelist == NULL )
        return( 0 );
    for( n = 2, i = 0; n <= sqrt_int_max; n++ ) {
        if( array[n] == 1 )
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
