#include <stdio.h>

#define MAX_ARRAY   (100000000)
#define MAX_ARRAY_SQRT (10000)

char    array[MAX_ARRAY];


int main( void )
{
    int n, i;

    /*  配列を初期化する    */
    for( i = 0; i < MAX_ARRAY; i++ )
        array[i] = 1;

    /*  配列をふるいにかける    */
    for( n = 2; n <= MAX_ARRAY_SQRT; n++ ) {
        if( array[n] == 1 ) {
            for( i = n * n; i < MAX_ARRAY; i += n )
                array[i] = 0;
        }
    }

    /*  ふるいで残った数は素数である    */
    for( n = 2; n < MAX_ARRAY; n++ ) {
        if( array[n] == 1 )
            printf( "%d\n", n );
    }

    return( 0 );
}
