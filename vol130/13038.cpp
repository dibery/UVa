#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100000;

int dfs( vector<int> adj[], int len[], int v )
{
	if( len[ v ] )
		return len[ v ];
	if( adj[ v ].empty() )
		return len[ v ] = 1;
	for( int& u: adj[ v ] )
		len[ v ] = max( len[ v ], dfs( adj, len, u ) + 1 );
	return len[ v ];
}

int main()
{
	int T, v, e, a, b;

	scanf( "%d", &T );
	for( int t = 1; t <= T; ++t )
	{
		vector<int> adj[ N ];
		int len[ N ] = { 0 };
		bool pointed[ N ] = { false };

		for( scanf( "%d %d", &v, &e ); e-- && scanf( "%d %d", &a, &b ); )
			adj[ --a ].push_back( --b ), ++pointed[ b ];
		for( int i = 0; i < v; ++i )
			if( !pointed[ i ] )
				dfs( adj, len, i );
		printf( "Case %d: %d\n", t, *max_element( len, len + v ) );
	}
}
