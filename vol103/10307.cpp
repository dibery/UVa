#include<bits/stdc++.h>
#define X front().first
#define Y front().second
using namespace std;
typedef pair<int,int> pii;

int main()
{
	int t, h, w, brd[ 50 ][ 50 ] = { { 0 } }, id = 0;
	char in[ 100 ];

	for( scanf( "%d", &t ); t--; id = 0 )
	{
		scanf( "%d %d\n", &w, &h );
		for( int i = 0; i < h; ++i )
		{
			gets( in );
			for( int j = 0; j < w && in[ j ]; ++j )
				if( in[ j ] == '#' )
					brd[ i ][ j ] = -1;
				else if( in[ j ] == ' ' )
					brd[ i ][ j ] = 0;
				else
					brd[ i ][ j ] = ++id;
		}

		int adj[ 102 ][ 102 ] = { { 0 } }, ans = 0;
		bool vis[ 102 ] = { false };
		priority_queue<pii,vector<pii>,greater<pii> > mst;

		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				if( brd[ i ][ j ] > 0 )
				{
					bool vis[ 102 ][ 102 ] = { { false } };
					int dist[ 102 ][ 102 ] = { { 0 } };
					queue<pii> bfs;

					vis[ i ][ j ] = true;
					for( bfs.push( make_pair( i, j ) ); !bfs.empty(); bfs.pop() )
						for( int m = bfs.X-1; m <= bfs.X+1; ++m )
							for( int n = bfs.Y-1; n <= bfs.Y+1; ++n )
								if( ( m != bfs.X ) != ( n != bfs.Y ) && !vis[ m ][ n ] && brd[ m ][ n ] >= 0 )
								{
									dist[ m ][ n ] = dist[ bfs.X ][ bfs.Y ] + 1;
									vis[ m ][ n ] = true;
									bfs.push( make_pair( m, n ) );
									if( brd[ m ][ n ] > 0 )
										adj[ brd[ i ][ j ] ][ brd[ m ][ n ] ] = adj[ brd[ m ][ n ] ][ brd[ i ][ j ] ] = dist[ m ][ n ];
								}
				}

		for( mst.push( make_pair( 0, 1 ) ); !mst.empty(); )
			if( vis[ mst.top().second ] )
				mst.pop();
			else
			{
				int V = mst.top().second, D = mst.top().first;
				mst.pop();
				vis[ V ] = true;
				ans += D;
				for( int i = 0; i < 102; ++i )
					if( adj[ V ][ i ] && !vis[ i ] )
						mst.push( make_pair( adj[ V ][ i ], i ) );
			}
		printf( "%d\n", ans );
	}
}
