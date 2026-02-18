#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE  (1024)

int main( int ac, char *av[] )
{
    int i, n, *primelist, d;
    char buf[BUF_SIZE];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 ) {
        fprintf( stderr, "usage : brotherprime d\n" );
        return( 1 );
    }
    d = (int)strtol( av[1], NULL, 10 );
    if( d < 2 ) {
        fprintf( stderr, "bad parameter\n" );
        return( 1 );
    }

    /*  ペア候補素数を格納する配列を用意  */
    if( ( primelist = calloc( d, sizeof(int) ) ) == NULL ) {
        fprintf( stderr, "calloc failed\n" );
        return( 1 );
    }
    for( i = 0; i < d; i++ )
        primelist[i] = 0;

    /*  兄弟素数を探す  */
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        n = (int)strtol( buf, NULL, 10 );
        if( n == 0 )
            continue;
        for( i = 0; i < d; i++ ) {
            if( primelist[i] != 0 && n - primelist[i] == d)
                printf( "%d %d\n", primelist[i], n );
        }
        for( i = 1; i < d; i++ )
            primelist[i] = primelist[i - 1];
        primelist[0] = n;
    }

    free( primelist );

    return( 0 );
}
