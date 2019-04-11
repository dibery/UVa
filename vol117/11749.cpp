#include<bits/stdc++.h>
using namespace std;
long long adj[ 500 ][ 500 ];

int dfs( int p, bool vis[], int link, int v )
{
	int size = 1;

	vis[ p ] = true;
	for( int i = 0; i < v; ++i )
		if( adj[ p ][ i ] == link && !vis[ i ] )
			size += dfs( i, vis, link, v );

	return size;
}

int main()
{
	for( int v, e; scanf( "%d %d", &v, &e ) && v; )
	{
		int ans = 0;
		long long use = INT_MIN;
		bool vis[ 500 ] = { false };

		fill( adj[ 0 ], adj[ 500 ], LLONG_MIN );
		for( long long a, b, w; e-- && scanf( "%lld %lld %lld", &a, &b, &w ); )
		{
			--a;
			--b;
			adj[ a ][ b ] = max( adj[ a ][ b ], w );
			adj[ b ][ a ] = max( adj[ b ][ a ], w );
			use = max( use, w );
		}

		for( int i = 0; i < v; ++i )
			if( !vis[ i ] )
				ans = max( ans, dfs( i, vis, use, v ) );
		printf( "%d\n", ans );
	}
}
