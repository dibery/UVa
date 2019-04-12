#include<bits/stdc++.h>
#define N 100
using namespace std;

int karp( list<int>*, int, int ), bfs( list<int>*, int[], int[][N], int, int );
int T, v, e, cap[ N ][ N ];

int main()
{
	scanf( "%d", &T );
	for( int t = 1, start; t <= T; ++t, puts( "" ) )
	{
		list<int> adj[ N ], ans;

		scanf( "%d %d %d", &v, &e, &start );
		memset( cap, 0, sizeof( cap ) );
		--start;
		for( int x, y; e-- && scanf( "%d %d", &x, &y ); )
		{
			--x;
			--y;
			cap[ x ][ y ] = cap[ y ][ x ] = 1;
			adj[ x ].push_back( y );
			adj[ y ].push_back( x );
		}

		for( int i = 0; i < v; ++i )
			if( i != start && karp( adj, start, i ) > 1 )
				ans.push_back( i );
		printf( "Case %d:", t );
		if( ans.empty() )
			printf( " none" );
		else
			for( auto i: ans )
				printf( " %d", i + 1 );
	}
}

int karp( list<int> adj[], int s, int t )
{
	int flow[ N ][ N ] = { { 0 } }, res[ N ][ N ] = { { 0 } }, prev[ N ] = { 0 }, f, df;
	memcpy( res, cap, sizeof( cap ) );

	for( f = 0; df = bfs( adj, prev, res, s, t ); f += df )
		for( int i = prev[ t ], j = t; i != j; i = prev[ j = i ] )
		{
			flow[ i ][ j ] += df;
			flow[ j ][ i ] -= df;
			res[ i ][ j ] = cap[ i ][ j ] - flow[ i ][ j ];
			res[ j ][ i ] = cap[ j ][ i ] - flow[ j ][ i ];
		}

	return f;
}

int bfs( list<int> adj[], int prev[], int res[][N], int s, int t )
{
	queue<int> Q;
	bool vis[ N ] = { false };
	int current[ N ];

	vis[ s ] = true;
	prev[ s ] = s;
	current[ s ] = INT_MAX;

	for( Q.push( s ); !Q.empty(); Q.pop() )
	{
		int p = Q.front();

		for( auto i: adj[ p ] )
			if( !vis[ i ] && res[ p ][ i ] > 0 )
			{
				vis[ i ] = true;
				prev[ i ] = p;
				current[ i ] = min( current[ p ], res[ p ][ i ] );
				if( i == t )
					return current[ t ];
				Q.push( i );
			}
	}
	return 0;
}
