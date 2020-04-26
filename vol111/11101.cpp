#include<bits/stdc++.h>
using namespace std;

int brd[ 2001 ][ 2001 ];

int main()
{
	for( int a, b; scanf( "%d", &a ) && a; )
	{
		queue<pair<int,int>> bfs;
		int ans = INT_MAX;

		memset( brd, -1, sizeof( brd ) );
		for( int x, y, i = 0; i < a && scanf( "%d %d", &x, &y ); ++i )
			brd[ x ][ y ] = 0, bfs.emplace( x, y );
		scanf( "%d", &b );
		for( int x, y, i = 0; i < b && scanf( "%d %d", &x, &y ); ++i )
			brd[ x ][ y ] = INT_MAX;

		while( !bfs.empty() && ans == INT_MAX )
		{
			int x = bfs.front().first, y = bfs.front().second;
			bfs.pop();
			for( int i = x - 1; i <= x + 1; ++i )
				for( int j = y - 1; j <= y + 1; ++j )
					if( i == x ^ j == y && i >= 0 && i < 2001 && j >= 0 && j < 2001 )
						if( brd[ i ][ j ] == -1 )
							brd[ i ][ j ] = brd[ x ][ y ] + 1, bfs.emplace( i, j );
						else if( brd[ i ][ j ] == INT_MAX )
							ans = brd[ x ][ y ] + 1;
		}
		printf( "%d\n", ans );
	}
}
