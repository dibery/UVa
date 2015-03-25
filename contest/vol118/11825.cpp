#include<bits/stdc++.h>
using namespace std;

bool crack( int state, int adj[ 16 ], int size )
{
	for( int i = 0; i < size; ++i )
		if( !( state & adj[ i ] ) )
			return false;
	return true;
}

void dfs( int sol[], int index, int size, int& ans, int mark = 0, int depth = 0 )
{
	ans = max( ans, depth );
	for( int i = index; i+ans-depth < size; ++i )
		if( !( mark & sol[ i ] ) )
			dfs( sol, i+1, size, ans, mark | sol[ i ], depth+1 );
}

int main()
{
	for( int node, t = 0; scanf( "%d", &node ) && node; )
	{
		int sol[ 1<<16 ] = { 0 }, adj[ 16 ] = { 0 }, size = 0, ans = 0;

		for( int i = 0, size, n; i < node; adj[ i ] |= 1 << i, ++i )
			for( scanf( "%d", &size ); size--; )
				scanf( "%d", &n ), adj[ i ] |= 1 << n;

		for( int i = 1; i < 1<<node; ++i )
			if( crack( i, adj, node ) && all_of( sol, sol+size, [ i ] ( int n ) { return ( n & i ) != n; } ) )
				sol[ size++ ] = i;

		dfs( sol, 0, size, ans );
		printf( "Case %d: %d\n", ++t, ans );
	}
}
