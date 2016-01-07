#include<bits/stdc++.h>
#define V Q.front()
using namespace std;
const int N = 205;
int karp( int[][N], int, int, int ), bfs( int[][N], int[][N], int[], int, int, int );

int main()
{
	for( int man, query; scanf( "%d %d", &man, &query ) == 2; )
	{
		int gene[ N ][ N ] = { { 0 } }, O[ N ] = { 0 };

		for( int i = 1, n; i <= man; ++i )
		{
			scanf( "%d", &n );
			++gene[ 0 ][ i ];
			O[ i - 1 ] = n < man;
			for( int j = 0, blood; j < n; ++j )
				scanf( "%d", &blood ), gene[ i ][ man + blood ] = 1;
		}

		for( int size; query--; )
		{
			bool ok;

			scanf( "%d", &size );
			for( int i = 1; i <= man; ++i )
				gene[ man + i ][ 2 * man + 1 ] = 0;
			for( int i = 0, n; i < size; ++i )
				scanf( "%d", &n ), ++gene[ man + n ][ 2 * man + 1 ];

			if( !size )
				ok = find( O, O + man, false ) == O + man;
			else
				ok = karp( gene, 2 * man + 2, 0, 2 * man + 1 ) == size;
			puts( ok? "Y" : "N" );
		}
	}
}

int karp( int G[][ N ], int size, int S, int T )
{
	int f = 0, df, flow[ N ][ N ] = { { 0 } }, prev[ N ] = { 0 };

	for( ; df = bfs( G, flow, prev, size, S, T ); f += df )
		for( int i = prev[ T ], j = T; i != j; i = prev[ j = i ] )
			flow[ i ][ j ] += df, flow[ j ][ i ] -= df;
	return f;
}

int bfs( int G[][ N ], int F[][ N ], int prev[], int size, int S, int T )
{
	queue<int> Q;
	int flow[ N ] = { 0 };
	bool vis[ N ] = { false };

	flow[ S ] = INT_MAX;
	prev[ S ] = S;
	vis[ S ] = true;

	for( Q.push( S ); !Q.empty(); Q.pop() )
		for( int i = 0; i < size; ++i )
			if( !vis[ i ] && G[ V ][ i ] - F[ V ][ i ] > 0 )
			{
				prev[ i ] = V;
				vis[ i ] = true;
				flow[ i ] = min( flow[ V ], G[ V ][ i ] - F[ V ][ i ] );
				if( i != T )
					Q.push( i );
				else
					return flow[ i ];
			}
	return 0;
}
