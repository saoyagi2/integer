#include <stdio.h>
#include <stdlib.h>

int set_ruler( int pos, int length, int mark_count, int *ruler );
int check_ruler( int mark_count, int *ruler );
void print_ruler( int mark_count, int *ruler );

long long nodes;
int ogrlength[] = { 0, 1, 3, 6, 11, 17, 25, 34, 44, 55, 72, 85, 106, 127, 151, 177, 199, 216, 246, 283, 333, 356, 372, 425, 480, 492 };

int main( int ac, char *av[] )
{
    int mark_count, *ruler, length;
    int i;

    /* コマンドラインからマーク数を決定する */
    if( ac < 2 ) {
        printf( "usage : ogr2 mark_count\n" );
        return( 1 );
    }
    mark_count = (int)strtol( av[1], NULL, 10 );
    if( mark_count < 2 ) {
        printf( "bad parameter\n" );
        return( 1 );
    }

    /* ruler用配列を確保する */
    ruler = calloc( mark_count, sizeof(int) );
    if( ruler == NULL )
        return( 1 );

    /* 変数を初期化する */
    length = ogrlength[mark_count - 1];
    nodes = 0;

    setbuf( stdout, NULL );
    while( 1 ) {
        /* ruler初期化 */
        for( i = 0; i < mark_count; i++ )
            ruler[i] = 0;

        /* ruler生成 */
        if( set_ruler( 1, length, mark_count, ruler ) )
            break;

        /* 長さを1伸ばす */
        length++;
    }

    /* 計算回数を表示 */
    printf( "%lld nodes\n", nodes );

    return( 0 );
}


/* ruler生成 */
int set_ruler( int pos, int length, int mark_count, int *ruler )
{
    int i, length2, ret;

    if( pos <= 2 || check_ruler( pos, ruler ) ) {
        /* 指定markのgolomb rulerならOGRである */
        if( pos == mark_count ) {
            print_ruler( mark_count, ruler );
            return( 1 );
        }
    }
    else {
        return( 0 );
    }

    /* 要素を一つ増やして再帰呼び出し */
    ret = 0;
    length2 = length - ogrlength[mark_count - pos - 1];
    for( i = ruler[pos - 1] + 1; i <= length2; i++ ) {
        ruler[pos] = i;
        if( set_ruler( pos + 1, length, mark_count, ruler ) )
            ret = 1;
    }
    return( ret );
}


/* golomb ruler判定 */
int check_ruler( int mark_count, int *ruler )
{
    int n1, n2, n3, n4;
    int d1, d2;

    nodes++;

    for( n1 = 0; n1 < mark_count - 1; n1++ ) {
        for( n2 = n1 + 1; n2 < mark_count; n2++ ) {
            d1 = ruler[n2] - ruler[n1];
            for( n3 = n1 + 1; n3 < mark_count - 1; n3++ ) {
                for( n4 = n3 + 1; n4 < mark_count; n4++ ) {
                    d2 = ruler[n4] - ruler[n3];
                    /* 差の等しい要素の組があれば偽 */
                    if( d1 == d2 )
                        return( 0 );
                }
            }
        }
    }

    return( 1 );
}


/* ruler表示 */
void print_ruler( int mark_count, int *ruler )
{
    int mark;

    for( mark = 0; mark < mark_count; mark++ ) {
        printf( "%d", ruler[mark] );
        if( mark != mark_count - 1 )
            printf( "-" );
    }
    printf( "\n" );
}
