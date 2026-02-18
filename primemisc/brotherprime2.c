#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE  (1024)

int main( int ac, char *av[] )
{
    long long i, n, *primelist, d, v;
    char buf[BUF_SIZE];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 ) {
        fprintf( stderr, "usage : brotherprime2 d2\n" );
        return( 1 );
    }
    d = strtoll( av[1], NULL, 10 );
    if( d < 2 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  ペア候補素数を格納する配列を用意  */
    if( ( primelist = calloc( d, sizeof(long long) ) ) == NULL ) {
        fprintf( stderr, "calloc failed\n" );
        return( 1 );
    }
    for( i = 0; i < d; i++ )
        primelist[i] = 0;

    /*  兄弟素数を探す  */
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        v = strtoll( buf, NULL, 10 );
        if( v == 0 )
            continue;
        n = primelist[0] + v;
        for( i = 0; i < d; i++ ) {
            if( primelist[i] != 0 && n - primelist[i] == d )
                printf( "%lld %lld\n", primelist[i], n );
        }
        for( i = 1; i < d; i++ )
            primelist[i] = primelist[i - 1];
        primelist[0] = n;
    }

    free( primelist );

    return( 0 );
}
