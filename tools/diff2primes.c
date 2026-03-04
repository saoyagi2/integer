#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE  (1024)

int main( void )
{
    long long d, prev_p;
    char buf[BUF_SIZE];

    prev_p = 0;
    while( fgets( buf, BUF_SIZE, stdin ) ) {
        if( ( d = strtoll( buf, NULL, 10 ) ) == 0 )
            continue;
        printf( "%lld\n", prev_p + d );
        prev_p = prev_p + d;
    }

    return( 0 );

}
