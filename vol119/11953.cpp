#include<cstdio>
void dfs( char sea[ 101 ][ 101 ], int i, int j, int size )
{
    if( i < 0 || j < 0 || i >= size || j >= size || sea[ i ][ j ] == '.' )
        return;
    sea[ i ][ j ] = '.';
    for( int m = i-1; m <= i+1; ++m )
        for( int n = j-1; n <= j+1; ++n )
            if( m == i ^ n == j )
                dfs( sea, m, n, size );
}

int main()
{
    int t, size;
    char sea[ 101 ][ 101 ];
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        int boat = 0;
        scanf( "%d\n", &size );
        for( int i = 0; i < size; ++i )
            gets( sea[ i ] );
        for( int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j )
                if( sea[ i ][ j ] == 'x' )
                {
                    ++boat;
                    dfs( sea, i, j, size );
                }
        printf( "Case %d: %d\n", i, boat );
    }

    return 0;
}
