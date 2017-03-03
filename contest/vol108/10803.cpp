#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
	int T, pt, x[ 100 ], y[ 100 ];

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d", &pt ); ++t )
	{
		double apsp[ 100 ][ 100 ], ans = -1;

		for( int i = 0; i < pt; ++i )
			scanf( "%d %d", x + i, y + i );

		fill( apsp[ 0 ], apsp[ 100 ], INT_MAX );
		for( int i = 0; i < pt; ++i )
			for( int j = 0; j < pt; ++j )
				if( i != j && pow( x[ i ] - x[ j ], 2 ) + pow( y[ i ] - y[ j ], 2 ) <= 100 )
					apsp[ i ][ j ] = apsp[ j ][ i ] = hypot( x[ i ] - x[ j ], y[ i ] - y[ j ] );
		for( int m = 0; m < pt; ++m )
			for( int b = 0; b < pt; ++b )
				for( int e = 0; e < pt; ++e )
					if( apsp[ b ][ m ] != INT_MAX && apsp[ m ][ e ] != INT_MAX )
						apsp[ b ][ e ] = min( apsp[ b ][ e ], apsp[ b ][ m ] + apsp[ m ][ e ] );

		for( int i = 0; i < pt; ++i )
			for( int j = i + 1; j < pt; ++j )
				ans = max( ans, apsp[ i ][ j ] );
		if( ans == -1 || ans == INT_MAX )
			printf( "Case #%d:\nSend Kurdy\n\n", t );
		else
			printf( "Case #%d:\n%.4f\n\n", t, ans );
	}
}
