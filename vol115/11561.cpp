#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int c, r, x, y; scanf( "%d %d\n", &c, &r ) == 2; )
	{
		char brd[ 50 ][ 51 ];

		for( int i = 0; i < r; ++i )
		{
			gets( brd[ i ] );
			if( strchr( brd[ i ], 'P' ) )
				x = i, y = strchr( brd[ i ], 'P' ) - brd[ i ];
		}

		int ans = 0;
		queue<pair<int,int>> bfs;

		for( bfs.push( make_pair( x, y ) ); !bfs.empty(); bfs.pop() )
		{
			int x = bfs.front().first, y = bfs.front().second;
			bool trap = false;

			if( brd[ x ][ y ] == '#' )
				continue;

			ans += brd[ x ][ y ] == 'G';
			brd[ x ][ y ] = '#';
			
			for( int m = x - 1; m <= x + 1; ++m )
				for( int n = y - 1; n <= y + 1; ++n )
					if( m == x ^ n == y )
						trap |= brd[ m ][ n ] == 'T';
			if( trap )
				continue;
			
			for( int m = x - 1; m <= x + 1; ++m )
				for( int n = y - 1; n <= y + 1; ++n )
					if( m == x ^ n == y && ( brd[ m ][ n ] == 'G' || brd[ m ][ n ] == '.' ) )
						bfs.push( make_pair( m, n ) );
		}
		
		printf( "%d\n", ans );
	}
}
