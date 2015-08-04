#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int size; scanf( "%d", &size ) == 1; )
	{
		char brd[ 101 ][ 101 ] = { { 0 } };
		unsigned int dist[ 100 ][ 100 ] = { { 0 } }, ans = UINT_MAX;

		for( int i = 0; i < size; ++i )
			scanf( "%s", brd[ i ] );

		for( int capital = 0; capital < 1024; ++capital )
			if( ( isupper( **brd ) != 0 ) == ( ( capital & 1 << tolower( **brd ) - 'a' ) != 0 ) )
			{
				queue<int> bfs;
				fill( dist[ 0 ], dist[ size ], UINT_MAX );
				**dist = 1;

				for( bfs.push( 0 ); !bfs.empty() && dist[ size-1 ][ size-1 ] == UINT_MAX; bfs.pop() )
				{
					int f = bfs.front(), x = f / 100, y = f % 100;
					for( int i = x-1; i <= x+1; ++i )
						for( int j = y-1; j <= y+1; ++j )
							if( i >= 0 && i < size && j >= 0 && j < size && i == x ^ j == y && dist[ i ][ j ] == UINT_MAX && ( isupper( brd[ i ][ j ] ) != 0 ) == ( ( capital & 1 << tolower( brd[ i ][ j ] ) - 'a' ) != 0 ) )
							{
								dist[ i ][ j ] = dist[ x ][ y ] + 1;
								bfs.push( i*100 + j );
							}
				}
				ans = min( ans, dist[ size-1 ][ size-1 ] );
			}
		printf( "%d\n", ans );
	}
}
