#include<cstdio>
const char oil = '@', no = '*';
int h, w;
void DFS( char field[ 100 ][ 101 ], int x, int y, bool visited[ 100 ][ 100 ] )
{
    if( x < 0 || y < 0 || x == h || y == w )
        return;
    visited[ x ][ y ] = true;
    for( int i = x-1; i <= x+1; ++i )
        for( int j = y-1; j <= y+1; ++j )
            if( field[ i ][ j ] == oil && !visited[ i ][ j ] )
                DFS( field, i, j, visited );
}

int main()
{
    while( scanf( "%d %d\n", &h, &w ) && h )
    {
        int tank = 0;
        char field[ 100 ][ 101 ];
        bool visited[ 100 ][ 100 ] = { false };
        for( int i = 0; i < h; ++i )
            gets( field[ i ] );
        for( int i = 0; i < h; ++i )
            for( int j = 0; j < w; ++j )
                if( field[ i ][ j ] == oil && !visited[ i ][ j ] )
                    DFS( field, i, j, visited ), ++tank;
        printf( "%d\n", tank );
    }
	return 0;
}