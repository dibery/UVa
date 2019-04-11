#include<cstdio>
#include<cstring>
const int pow2[] = { 1, 2, 4, 8, 16, 32, 64 };
inline bool battle( int p1, int p2, int round )
{
    if( p1 == p2 )
        return false;
    for( int i = 1; i < round; ++i )
        if( p1 / pow2[ i ] == p2 / pow2[ i ] )
            return false;
    return( p1 / pow2[ round ] == p2 / pow2[ round ] );
}

int main()
{
    char nation[ 16 ][ 11 ];
    int win[ 16 ][ 16 ];
    double prob[ 16 ][ 5 ] = { 0 };
    memset( prob, 0, sizeof( prob ) );

    for( int i = 0; i < 16; ++i )
        scanf( "%s", nation+i );
    for( int i = 0; i < 16; ++i )
        for( int j = 0; j < 16; ++j )
            scanf( "%d", &win[ i ][ j ] );
    for( int i = 0; i < 16; ++i )
        prob[ i ][ 0 ] = 1;
    for( int j = 1; j <= 4; ++j )
        for( int i = 0; i < 16; ++i )
            for( int k = 0; k < 16; ++k )
                if( battle( i, k, j ) )
                    prob[ i ][ j ] += win[ i ][ k ] / 100.0 * prob[ i ][ j-1 ] * prob[ k ][ j-1 ];
    for( int i = 0; i < 16; ++i )
        printf( "%-10s p=%.2f%%\n", nation[ i ], prob[ i ][ 4 ]*100 );

    return 0;
}
