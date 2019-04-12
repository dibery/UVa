#include<bits/stdc++.h>
#define N 201
#define p Q.front()
using namespace std;

int karp( list<int>[], int, int ), bfs( list<int>[], int[], int [][N], int, int );

int main()
{
	for( int A, B, task; scanf( "%d %d %d", &A, &B, &task ) == 3; )
	{
		list<int> adj[ N ];

		for( int i, j; task--; )
		{
			scanf( "%*d %d %d", &i, &j );
			if( i && j )
				adj[ i ].push_back( j+100 ), adj[ j+100 ].push_back( i );
		}
		for( int i = 1; i < A; ++i )
			adj->push_back( i );
		for( int j = 1; j < B; ++j )
			adj[ 100+j ].push_back( 200 );

		printf( "%d\n", karp( adj, 0, 200 ) );
	}
}

int karp( list<int> adj[], int s, int t )
{
	int flow[ N ][ N ] = { { 0 } }, prev[ N ] = { 0 }, f;

	for( f = 0; bfs( adj, prev, flow, s, t ); ++f )
		for( int i = prev[ t ], j = t; i != j; i = prev[ j = i ] )
			++flow[ i ][ j ], --flow[ j ][ i ];

	return f;
}

int bfs( list<int> adj[], int prev[], int flow[][N], int s, int t )
{
	queue<int> Q;
	bool vis[ N ] = { true };

	for( Q.push( s ); !Q.empty(); Q.pop() )
		for( list<int>::iterator i = adj[ p ].begin(); i != adj[ p ].end(); ++i )
			if( !vis[ *i ] && flow[ p ][ *i ] < ( p > 100 && *i < 100? 0 : 1 ) )
			{
				vis[ *i ] = true;
				prev[ *i ] = p;
				if( *i == t )
					return 1;
				else
					Q.push( *i );
			}
	return 0;
}
