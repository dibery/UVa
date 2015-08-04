#include<bits/stdc++.h>
#define N 5002
#define END 2*h*w+1
using namespace std;

int karp( list<int>*, int, int ), bfs( list<int>*, int[], int, int );
int t, h, w, rob, cap[ N ][ N ], flow[ N ][ N ];
inline int id( int i, int j, int o = 0 ) { return --i * w + j + o * h*w; }

int main()
{
	for( scanf( "%d", &t ); t--; )
	{
		list<int> adj[ N ];

		scanf( "%d %d %d", &h, &w, &rob );
		memset( cap, 0, sizeof( cap ) );
		for( int i = 0, a, b; i < rob; ++i )
		{
			scanf( "%d %d", &a, &b );
			adj->push_back( id( a, b ) );
			cap[ 0 ][ id( a, b ) ] = 1;
		}
		for( int i = 1; i <= h*w; ++i )
			adj[ i ].push_back( i+h*w ), cap[ i ][ i+h*w ] = 1;
		for( int i = 2; i < h; ++i )
			for( int j = 2; j < w; ++j )
				for( int m = i-1; m <= i+1; ++m )
					for( int n = j-1; n <= j+1; ++n )
						if( m == i ^ n == j )
							adj[ id( i, j, 1 ) ].push_back( id( m, n ) ), cap[ id( i, j, 1 ) ][ id( m, n ) ] = 1;
		for( int i = 1; i <= w; ++i )
		{
			adj[ id( 1, i ) ].push_back( END );
			adj[ id( h, i ) ].push_back( END );
			cap[ id( 1, i ) ][ END ] = cap[ id( h, i ) ][ END ] = 1;
		}
		for( int i = 2; i < h; ++i )
		{
			adj[ id( i, 1 ) ].push_back( END );
			adj[ id( i, w ) ].push_back( END );
			cap[ id( i, 1 ) ][ END ] = cap[ id( i, w ) ][ END ] = 1;
		}

		puts( karp( adj, 0, 2*h*w+1 ) == rob? "possible" : "not possible" );
	}
}

int karp( list<int> adj[], int s, int t )
{
	int prev[ N ] = { 0 }, f, df;
	memset( flow, 0, sizeof( flow ) );

	for( f = 0; df = bfs( adj, prev, s, t ); f += df )
		for( int i = prev[ t ], j = t; i != j; i = prev[ j = i ] )
		{
			flow[ i ][ j ] += df;
			flow[ j ][ i ] -= df;
		}

	return f;
}

int bfs( list<int> adj[], int prev[], int s, int t )
{
	queue<int> Q;
	bool vis[ N ] = { false };
	int current[ N ];

	vis[ s ] = true;
	prev[ s ] = s;
	current[ s ] = INT_MAX;
	Q.push( s );

	while( !Q.empty() )
	{
		int p = Q.front();
		Q.pop();

		for( list<int>::iterator i = adj[ p ].begin(); i != adj[ p ].end(); ++i )
			if( !vis[ *i ] && cap[ p ][ *i ] > flow[ p ][ *i ] )
			{
				vis[ *i ] = true;
				prev[ *i ] = p;
				current[ *i ] = min( current[ p ], cap[ p ][ *i ] - flow[ p ][ *i ] );
				Q.push( *i );
				if( *i == t )
					return current[ t ];
			}
	}
	return 0;
}
