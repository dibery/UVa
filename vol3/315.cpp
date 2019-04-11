#include<cstdio>
#include<sstream>

void dfs( bool adj[][ 100 ], bool vis[], int node, int v, int ignore )
{
	vis[ v ] = true;
	for( int i = 0; i < node; ++i )
		if( adj[ v ][ i ] && !vis[ i ] && i != ignore )
			dfs( adj, vis, node, i, ignore );
}

bool articulate( bool adj[][ 100 ], int node, int test )
{
	bool vis[ 100 ] = { false };

	dfs( adj, vis, node, !test, test );
	for( int i = 0; i < node; ++i )
		if( i != test && !vis[ i ] )
			return true;
	return false;
}

int main()
{
	for( int node; scanf( "%d", &node ) && node; )
	{
		bool adj[ 100 ][ 100 ] = { { false } };
		char s[ 500 ] = { 0 };
		int ans = 0;

		for( int v; scanf( "%d", &v ) && v; )
		{
			std::stringstream ss( gets( s ) );
			--v;
			for( int u; ss >> u; )
				--u, adj[ u ][ v ] = adj[ v ][ u ] = true;
		}

		for( int i = 0; i < node; ++i )
			ans += articulate( adj, node, i );
		printf( "%d\n", ans );
	}
}
