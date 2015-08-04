#include<bits/stdc++.h>
#define N 100
#define V Q.front()
using namespace std;
int karp( int[][N], int, int, int ), bfs( int[][N], int[][N], int[], int, int, int );

int main()
{
	for( int vertex, t = 0, S, T, C, from, to, cap; scanf( "%d", &vertex ) && vertex; )
	{
		int G[ N ][ N ] = { { 0 } };

		for( cin >> S >> T >> C; C--; G[ from ][ to ] += cap, G[ to ][ from ] += cap )
			scanf( "%d %d %d", &from, &to, &cap ), --from, --to;
		printf( "Network %d\nThe bandwidth is %d.\n\n", ++t, karp( G, vertex, --S, --T ) );
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
