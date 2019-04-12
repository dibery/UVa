#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, r, c, m, n, w;

	scanf( "%d", &t );
	for( int T = 1; T <= t; ++T )
	{
		scanf( "%d %d %d %d %d", &r, &c, &m, &n, &w );

		bool vis[ 100 ][ 100 ] = { { true } }, skip[ 100 ][ 100 ] = { { false } };
		int reach[ 100 ][ 100 ] = { { 0 } }, odd = 0, even = 0;
		int dx[] = { m, m, -m, -m, n, n, -n, -n }, dy[] = { n, -n, n, -n, m, -m, m, -m };
		auto ok = [ r, c ] ( int p, int q ) { return p >= 0 && p < r && q >= 0 && q < c; };

		for( int i, j; w-- && scanf( "%d %d", &i, &j ); )
			skip[ i ][ j ] = true;

		queue<pair<int,int>> bfs;
		
		for( bfs.push( make_pair( 0, 0 ) ); !bfs.empty(); bfs.pop() )
		{
			int R = bfs.front().first, C = bfs.front().second;
			set<pair<int,int>> move;
			for( int i = 0; i < 8; ++i )
			{
				int nx = R + dx[ i ], ny = C + dy[ i ];
				if( move.find( make_pair( nx, ny ) ) != move.end() )
					continue;
				else
					move.insert( make_pair( nx, ny ) );
				reach[ R ][ C ] += ok( nx, ny ) && !skip[ nx ][ ny ];
				if( ok( nx, ny ) && !vis[ nx ][ ny ] && !skip[ nx ][ ny ] )
				{
					bfs.push( make_pair( nx, ny ) );
					vis[ nx ][ ny ] = true;
				}
			}
		}

		for( int i = 0; i < r; ++i )
			for( int j = 0; j < c; ++j )
				if( reach[ i ][ j ] & 1 )
					++odd;
				else if( reach[ i ][ j ] || i + j == 0 )
					++even;

		printf( "Case %d: %d %d\n", T, even, odd );
	}
}
