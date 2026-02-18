#include <stdio.h>
#include <stdlib.h>

int check_ruler( int mark_count, int *ruler );
void print_ruler( int mark_count, int *ruler );


int main( int ac, char *av[] )
{
    int mark, mark_count, *ruler, length, found;
    long long nodes;

    /* コマンドラインからマーク数を決定する */
    if( ac < 2 ) {
        printf( "usage : ogr mark_count\n" );
        return( 1 );
    }
    mark_count = (int)strtol( av[1], NULL, 10 );
    if( mark_count < 2 ) {
        printf( "bad parameter\n" );
        return( 1 );
    }

    /* ruler用配列を確保する */
    if( ( ruler = calloc( mark_count, sizeof(int) ) ) == NULL ) {
        fprintf( stderr, "calloc failed\n" );
        return( 1 );
    }

    /* ループ変数を初期化する */
    length = ( mark_count - 1 ) * mark_count / 2;
    found = 0;
    nodes = 0;

    /* OGR探索ループ */
    while( found == 0 ) {
        /* rulerを0,1,2...,lengthで初期化する */
        for( mark = 1; mark < mark_count - 1; mark++ )
            ruler[mark] = mark;
        ruler[mark_count - 1] = length;

        /* 長さがlengthのGRを探す */
        while( 1 ) {
            /* 計算回数をカウント */
            nodes++;

            /* golomb rulerであるか */
            if( check_ruler( mark_count, ruler ) == 1 ) {
                print_ruler( mark_count, ruler );
                found = 1;
            }

            /* markを一つ先に進める */
            for( mark = mark_count - 2; mark > 0; mark-- ) {
                if( ruler[mark] < length - ( mark_count - mark - 1 ) ) {
                    ruler[mark]++;
                    for( mark = mark + 1; mark < mark_count - 1; mark++ )
                        ruler[mark] = ruler[mark - 1] + 1;
                    break;
                }
            }
            /* 進めるマークが無ければ終了 */
            if( mark == 0 )
                break;
        }
        /* lengthを増やす */
        length++;
    }

    /* 計算回数を表示 */
    printf( "%lld nodes\n", nodes );

    free( ruler );

    return( 0 );
}


/* golomb ruler判定 */
int check_ruler( int mark_count, int *ruler )
{
    int n1, n2, n3, n4;
    int d1, d2;

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
