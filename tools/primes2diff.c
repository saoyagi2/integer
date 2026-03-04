#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE  (1024)

int main( void )
{
    long long p, prev_p;
    char buf[BUF_SIZE];

    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        if( ( p = strtoll( buf, NULL, 10 ) ) == 0 )
            continue;
        printf( "%lld\n", p - prev_p );
        prev_p = p;
    }

    return( 0 );

}
