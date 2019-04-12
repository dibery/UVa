#include<bits/stdc++.h>
using namespace std;

void dfs( list<int> adj[], int parent, int index, int time[], bool vis[], int back[], int size, int& t, set<int>& ap )
{
	time[ index ] = back[ index ] = ++t;
	vis[ index ] = true;

	for( list<int>::iterator i = adj[ index ].begin(); i != adj[ index ].end(); ++i )
		if( !vis[ *i ] )
		{
			dfs( adj, index, *i, time, vis, back, size, t, ap );
			back[ index ] = min( back[ index ], back[ *i ] );
			if( back[ *i ] > time[ index ] )
				ap.insert( min( *i, index ) * 1000 + max( *i, index ) );
		}
		else if( *i != parent )
			back[ index ] = min( back[ index ], back[ *i ] );
}

int main()
{
	for( int vertex, edge; scanf( "%d %d", &vertex, &edge ) && vertex; )
	{
		list<int> adj[ vertex ];
		set<int> ap;
		int time[ 1000 ] = { 0 }, back[ 1000 ] = { 0 }, t = 0;
		bool vis[ 1000 ] = { false };

		for( int i = 0, a, b; i < edge && scanf( "%d %d", &a, &b ); ++i )
			adj[ a ].push_back( b ), adj[ b ].push_back( a );

		dfs( adj, 0, 0, time, vis, back, vertex, t, ap );

		printf( "%lu", ap.size() );
		for( set<int>::iterator i = ap.begin(); i != ap.end(); ++i )
			printf( " %d %d", *i / 1000, *i % 1000 );
		puts( "" );
	}
}
