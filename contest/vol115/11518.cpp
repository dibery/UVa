#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void dfs( vector<int> adj[], int v, bool knock[] )
{
	if( knock[ v ] )
		return;
	knock[ v ] = true;
	for( int i = 0; i < adj[ v ].size(); ++i )
		dfs( adj, adj[ v ][ i ], knock );
	return;
}

int main()
{
	int t, from, to, vertex, edge, hand;

	for( scanf( "%d", &t ); t--; )
	{
		vector<int> adj[ 10000 ];
		bool knock[ 10000 ] = { false };

		for( scanf( "%d %d %d", &vertex, &edge, &hand ); edge--; adj[ --from ].push_back( --to ) )
			scanf( "%d %d", &from, &to );
		for( int n; hand--; )
		{
			scanf( "%d", &n );
			dfs( adj, --n, knock );
		}
		printf( "%ld\n", count( knock, knock + vertex, true ) );
	}
}
