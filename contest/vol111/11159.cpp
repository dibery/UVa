#include<bits/stdc++.h>
#define N 205
#define V Q.front()
using namespace std;
int karp( int[][N], int, int, int ), bfs( int[][N], int[][N], int[], int, int, int );

int main()
{
	int T, a[ 100 ], b[ 100 ], la, lb;

	scanf( "%d", &T );
	for( int t = 1; t <= T; ++t )
	{
		int G[ N ][ N ] = { { 0 } };

		scanf( "%d", &la );
		for( int i = 0; i < la; ++i )
			scanf( "%d", a + i );
		scanf( "%d", &lb );
		for( int i = 0; i < lb; ++i )
			scanf( "%d", b + i );
		for( int i = 0; i < la; ++i )
			for( int j = 0; j < lb; ++j )
				G[ i + 1 ][ j + 1 + la ] = a[ i ] == 0 && b[ j ] == 0 || a[ i ] && b[ j ] % a[ i ] == 0;
		for( int i = 1; i <= la; ++i )
			G[ 0 ][ i ] = 1;
		for( int i = 1; i <= lb; ++i )
			G[ i + la ][ la + lb + 1 ] = 1;
		printf( "Case %d: %d\n", t, karp( G, la + lb + 2, 0, la + lb + 1 ) );
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
