#include <stdio.h>
#include <stdlib.h>

int main( int ac, char *av[] )
{
    int n, m, d;
    char buf[1024];

    /*  コマンドラインから差を決定する    */
    if( ac < 2 )
        return( 1 );
    d = strtol( av[1], NULL, 10 );

    m = -1;
    while( fgets( buf, 1024, stdin ) ) {
        n = strtol( buf, NULL, 10 );
        if( m != -1 && n - d == m )
            printf( "%d %d\n", m, n );
        m = n;
    }

    return( 0 );
}
