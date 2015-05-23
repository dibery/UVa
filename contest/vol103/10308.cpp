#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

void dfs( int dist[], vector<pii> v[], bool vis[], int at = 0, int go = 0 )
{
	vis[ at ] = true;
	dist[ at ] = go;
	for( int i = 0; i < v[ at ].size(); ++i )
		if( !vis[ v[ at ][ i ].first ] )
			dfs( dist, v, vis, v[ at ][ i ].first, go + v[ at ][ i ].second );
}

int main()
{
	int from, to, D;
	char in[ 100 ], *p;
	vector<pii> adj[ 10000 ];

	while( ( p = gets( in ) ) || true )
		if( !*in || !p )
		{
			bool vis[ 10000 ] = { false };
			int dist[ 10000 ] = { 0 };

			dfs( dist, adj, vis );
			fill( vis, vis + 10000, false );
			dfs( dist, adj, vis, max_element( dist, dist + 10000 ) - dist );
			printf( "%d\n", *max_element( dist, dist + 10000 ) );
			for( int i = 0; i < 10000; ++i )
				adj[ i ].clear();
			if( !p )
				break;
		}
		else
		{
			sscanf( in, "%d %d %d", &from, &to, &D );
			adj[ --from ].push_back( make_pair( --to, D ) );
			adj[ to ].push_back( make_pair( from, D ) );
		}
}
