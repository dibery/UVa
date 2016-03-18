#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 10001;

vector<pii> edges;
vector<int> adj[ N ];
stack<int> rec;
set<int> all;
bool in[ N ] = { false };
int vis[ N ] = { 0 }, low[ N ] = { 0 }, New[ N ] = { 0 }, id = 0, ans = 0;

void dfs( int v )
{
	// low: the earliest node it can reach
	// in: whether a point is in stack or not
	vis[ v ] = low[ v ] = ++id;
	rec.push( v );
	in[ v ] = true;

	for( int& i: adj[ v ] )
	{
		if( !vis[ i ] )
			dfs( i );
		if( in[ i ] )
			low[ v ] = min( low[ v ], low[ i ] ); // Update low[]
	}
	if( low[ v ] == vis[ v ] ) // The first node found in a SCC
		while( true )
		{
			// Assign all nodes in this SCC to the first node
			in[ rec.top() ] = false;
			New[ rec.top() ] = v;
			if( rec.top() == v )
			{
				rec.pop();
				break;
			}
			rec.pop();
		}
}

int main()
{
	int t, v, e;

	scanf( "%d", &t );
	for( int N = 1; N <= t; ++N )
	{
		// Build the initial graph
		scanf( "%d %d", &v, &e );
		for( int a, b; e-- && scanf( "%d %d", &a, &b ); )
			if( a != b )
				edges.push_back( pii( a, b ) );
		for( auto& i: edges )
			adj[ i.first ].push_back( i.second );

		for( int i = 1; i <= v; ++i )
			if( !vis[ i ] )
				dfs( i );

		// Clear adj for a new graph for SCC and count all SCC
		for( auto& i: adj )
			i.clear();
		all.insert( New + 1, New + v + 1 );
		all.erase( 0 );

		// Create new graph with only SCC, with edges reversed
		for( auto& i: edges )
			if( New[ i.second ] != New[ i.first ] && adj[ New[ i.second ] ].empty() )
				adj[ New[ i.second ] ].push_back( New[ i.first ] );

		// How many are to be knocked down manually
		for( auto& i: all )
			ans += adj[ i ].empty();
		printf( "Case %d: %d\n", N, max( ans, 1 ) );

		// Clear
		edges.clear();
		memset( vis, id = ans = 0, sizeof( vis ) );
		memset( low, 0, sizeof( low ) );
		memset( New, 0, sizeof( New ) );
		memset( in, 0, sizeof( in ) );
		all.clear();
		for( auto& i: adj )
			i.clear();
		while( !rec.empty() )
			rec.pop();
	}
}
