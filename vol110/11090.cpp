#include<bits/stdc++.h>
using namespace std;

int main()
{
	const int MAX = 51;
	int T, v, e;

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d", &v, &e ); ++t )
	{
		int dist[ MAX ][ MAX ], adj[ MAX ][ MAX ];
		double ans = INT_MAX;
		bool vis[ MAX ] = { false };

		fill( *adj, adj[ 50 ], INT_MAX );
		for( int a, b, w; e-- && scanf( "%d %d %d", &a, &b, &w ); )
			--a, --b, adj[ a ][ b ] = min( adj[ a ][ b ], w );

		for( int x = 0; x < v; ++x )
			if( !vis[ x ] )
			{
				fill( *dist, dist[ MAX ], INT_MAX );
				dist[ 0 ][ x ] = 0;
				for( int pass = 1; pass <= v; ++pass )
					for( int i = 0; i < v; ++i )
						for( int j = 0; j < v; ++j )
							if( max( dist[ pass - 1 ][ j ], adj[ j ][ i ] ) != INT_MAX )
							{
								dist[ pass ][ i ] = min( dist[ pass ][ i ], dist[ pass - 1 ][ j ] + adj[ j ][ i ] );
								vis[ i ] = true;
							}

				for( int i = 0; i < v; ++i )
				{
					double tmp = 0;
					for( int j = 0; j < v; ++j )
						if( dist[ v ][ i ] != INT_MAX )
							tmp = max( tmp, ( dist[ v ][ i ] - dist[ j ][ i ] ) / double( v - j ) );
					if( tmp )
						ans = min( ans, tmp );
				}
			}

		if( ans != INT_MAX )
			printf( "Case #%d: %.2f\n", t, ans );
		else
			printf( "Case #%d: No cycle found.\n", t );
	}
}