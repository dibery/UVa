#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, fire, V;
	char in[ 100 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &fire, &V ); )
	{
		bool isfire[ 500 ] = { false };
		int adj[ 500 ][ 500 ] = { { 0 } }, fire_dist[ 500 ] = { 0 }, ans = 0, longest = INT_MAX;

		fill( adj[ 0 ], adj[ V ], INT_MAX );
		fill( fire_dist, fire_dist + V, INT_MAX );
		for( int i = 0; i < V; ++i )
			adj[ i ][ i ] = 0;

		for( int n; fire-- && scanf( "%d%*c", &n ); isfire[ --n ] = true );
		for( int u, v, w; gets( in ) && *in; adj[ u ][ v ] = adj[ v ][ u ] = w )
			sscanf( in, "%d %d %d", &u, &v, &w ), --u, --v;

		for( int m = 0; m < V; ++m )
			for( int b = 0; b < V; ++b )
				for( int e = 0; e < V; ++e )
					if( adj[ b ][ m ] != INT_MAX && adj[ m ][ e ] != INT_MAX )
						adj[ b ][ e ] = min( adj[ b ][ e ], adj[ b ][ m ] + adj[ m ][ e ] );
		for( int i = 0; i < V; ++i )
			for( int j = 0; j < V; ++j )
				if( isfire[ j ] )
					fire_dist[ i ] = min( fire_dist[ i ], adj[ i ][ j ] );
		for( int i = 0; i < V; ++i )
		{
			int now = INT_MIN;
			for( int j = 0; j < V; ++j )
				now = max( now, min( fire_dist[ j ], adj[ j ][ i ] ) );
			if( now < longest )
				longest = now, ans = i;
		}
		printf( "%d\n%s", ++ans, t? "\n" : "" );
	}
}
