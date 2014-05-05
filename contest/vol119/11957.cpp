#include<cstdio>
#include<cstring>
const char FREE = '.', WHITE = 'W', BLACK = 'B';
const int MOD = 1000007;
int process( char field[ 100 ][ 101 ], int ans[ 100 ][ 100 ], int i, int j, int len )
{
    if( ans[ i ][ j ] )
        return ans[ i ][ j ];
    if( i == 0 )
        return 1;
    int tmp = 0;
    if( j > 0 && j < len )
        if( field[ i-1 ][ j-1 ] == FREE )
            tmp += process( field, ans, i-1, j-1, len );
        else//
            if( i > 1 && j > 1 && field[ i-2 ][ j-2 ] == FREE )
                tmp += process( field, ans, i-2, j-2, len );
    if( j >= 0 && j < len-1 )
        if( field[ i-1 ][ j+1 ] == FREE )
            tmp += process( field, ans, i-1, j+1, len );
        else//
            if( i > 1 && j < len-2 && field[ i-2 ][ j+2 ] == FREE )
                tmp += process( field, ans, i-2, j+2, len );
    return ans[ i ][ j ] = tmp % MOD;
}

int main()
{
    int t, size;
    scanf( "%d", &t );

    for( int k = 1; k <= t; ++k )
    {
        char field[ 100 ][ 101 ] = { 0 };
        int ans[ 100 ][ 100 ] = { 0 }, pos;
        scanf( "%d", &size );
        for( int i = 0; i < size; ++i )
        {
            scanf( "%s", field[ i ] );
            if( strchr( field[ i ], WHITE ) )
                pos = strchr( field[ i ], WHITE ) - field[ i ] + i * 100;
        }
        printf( "Case %d: %d\n", k, pos / 100? process( field, ans, pos / 100, pos % 100, size ) : 0 );
    }

	return 0;
}