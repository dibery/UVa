#include<cstdio>
#include<cmath>
#include<numeric>

int main()
{
	double tight[ 10 ][ 101 ][ 10 ] = { { 0 } };

	for( int s = 0; s < 10; ++s )
	{
		for( int i = 0; i <= s; ++i )
			tight[ s ][ 1 ][ i ] = 1;
		for( int i = 2; i <= 100; ++i )
			for( int j = 0; j <= s; ++j )
				for( int k = j - 1; k <= j + 1; ++k )
					if( k >= 0 && k <= s )
						tight[ s ][ i ][ j ] += tight[ s ][ i - 1 ][ k ];
	}

	for( int k, n; scanf( "%d %d", &k, &n ) == 2; )
		printf( "%.5f\n", 100 * std::accumulate( tight[ k ][ n ], tight[ k ][ n + 1 ], 0. ) / pow( k + 1, n ) );
}
