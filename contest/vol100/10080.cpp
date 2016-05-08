#include<bits/stdc++.h>
#define N 205
#define V Q.front()
using namespace std;
int karp( int[][N], int, int, int ), bfs( int[][N], int[][N], int[], int, int, int );

int main()
{
	for( int gopher, hole, time, speed; scanf( "%d %d %d %d", &gopher, &hole, &time, &speed ) == 4; )
	{
		int G[ N ][ N ] = { { 0 } };
		double gx[ N ], gy[ N ], hx[ N ], hy[ N ];

		for( int i = 0; i < gopher; ++i )
			scanf( "%lf %lf", gx + i, gy + i );
		for( int i = 0; i < hole; ++i )
			scanf( "%lf %lf", hx + i, hy + i );
		for( int i = 0; i < gopher; ++i )
			for( int j = 0; j < hole; ++j )
				G[ i + 1 ][ j + gopher + 1 ] = hypot( gx[ i ] - hx[ j ], gy[ i ] - hy[ j ] ) <= speed * time;
		for( int i = 1; i <= gopher; ++i )
			G[ 0 ][ i ] = 1;
		for( int i = 1; i <= hole; ++i )
			G[ i + gopher ][ gopher + hole + 1 ] = 1;
		printf( "%d\n", gopher - karp( G, gopher + hole + 2, 0, gopher + hole + 1 ) );
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
