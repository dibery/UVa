#include<bits/stdc++.h>
#define N 1002
#define p Q.front()
using namespace std;

int karp( vector<int>[], int, int ), bfs( vector<int>[], int[], int [][N], int, int );

bool ok( char* has, char* cha )
{
	int t[ 26 ] = { 0 };
	while( *has )
		++t[ *has++ - 'a' ];
	while( *cha )
		--t[ *cha++ - 'a' ];
	for( int i = 0; i < 26; ++i )
		if( t[ i ] < 0 )
			return false;
	return true;
}

int main()
{
	for( int A, B; scanf( "%d %d\n", &A, &B ) == 2; )
	{
		vector<int> adj[ N ];
		char has[ 500 ][ 32 ], cha[ 500 ][ 32 ];

		for( int i = 0; i < A; ++i )
			gets( has[ i ] );
		for( int i = 0; i < B; ++i )
			gets( cha[ i ] );

		for( int i = 1; i <= A; ++i )
			adj->push_back( i );
		for( int j = 1; j <= B; ++j )
			adj[ 500+j ].push_back( 1001 );
		for( int i = 0; i < A; ++i )
			for( int j = 0; j < B; ++j )
				if( ok( has[ i ], cha[ j ] ) )
					adj[ i+1 ].push_back( j+501 ), adj[ j+501 ].push_back( i+1 );

		printf( "%d\n", karp( adj, 0, 1001 ) );
	}
}

int karp( vector<int> adj[], int s, int t )
{
	int flow[ N ][ N ] = { { 0 } }, prev[ N ] = { 0 }, f;

	for( f = 0; bfs( adj, prev, flow, s, t ); ++f )
		for( int i = prev[ t ], j = t; i != j; i = prev[ j = i ] )
			++flow[ i ][ j ], --flow[ j ][ i ];

	return f;
}

int bfs( vector<int> adj[], int prev[], int flow[][N], int s, int t )
{
	queue<int> Q;
	bool vis[ N ] = { true };

	for( Q.push( s ); !Q.empty(); Q.pop() )
		for( vector<int>::iterator i = adj[ p ].begin(); i != adj[ p ].end(); ++i )
			if( !vis[ *i ] && flow[ p ][ *i ] < ( p > 500 && *i < 500? 0 : 1 ) )
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
