#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, V, E;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		vector<int> adj[ 25 ];
		int ans = INT_MAX, D[ 25 ][ 25 ] = { { 0 } }, MD[ 25 ] = { 0 };

		scanf( "%d %d", &V, &E );
		for( int b, e; E-- && scanf( "%d %d", &b, &e ); )
			adj[ b ].push_back( e ), adj[ e ].push_back( b );

		for( int begin = 0; begin < V; ++begin )
		{
			queue<int> bfs;

			for( bfs.push( begin ); !bfs.empty(); bfs.pop() )
				for( int i: adj[ bfs.front() ] )
					if( i != begin && !D[ begin ][ i ] )
					{
						bfs.push( i );
						MD[ begin ] = D[ begin ][ i ] = D[ begin ][ bfs.front() ] + 1;
					}
		}

		for( int i = 0; i < V; ++i )
			for( int j: adj[ i ] )
				if( i < j )
				{
					bool subtract = true;

					if( MD[ i ] == MD[ j ] )
						for( int k = 0; k < V && subtract; ++k )
							subtract &= D[ i ][ k ] != MD[ i ] || D[ j ][ k ] != MD[ i ];
					ans = min( ans, MD[ i ] + MD[ j ] - ( MD[ i ] != MD[ j ] || subtract ) );
				}

		printf( "Case #%d:\n%d\n\n", n, ans );
	}
}
