#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, h, w, brd[ 100 ][ 100 ], size;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &h, &w );
		size = min( h, w );
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				scanf( "%d", brd[ i ] + j );

		int nurish[ 101 ][ 101 ][ 101 ], fish[ 101 ][ 101 ][ 101 ] = { 0 }, profit = 0;

		for( int i = 1; i <= 100; ++i )
			for( int j = 0; j <= 100; ++j )
				for( int k = 0; k <= 100; ++k )
					nurish[ i ][ j ][ k ] = INT_MAX >> 1;

		for( int i = 1; i <= size; ++i )
			for( int j = h-1; j >= 0; --j )
				for( int k = w-1; k >= 0; --k )
					nurish[ i ][ j ][ k ] = min( min( nurish[ i ][ j ][ k+1 ], nurish[ i ][ j+1 ][ k ] ), brd[ j ][ k ] + nurish[ i-1 ][ j+1 ][ k+1 ] );

		for( int i = 1; i <= size; ++i )
			for( int j = h-1; j >= 0; --j )
				for( int k = w-1; k >= 0; --k )
					fish[ i ][ j ][ k ] = max( max( fish[ i ][ j ][ k+1 ], fish[ i ][ j+1 ][ k ] ), brd[ j ][ k ] + fish[ i-1 ][ j+1 ][ k+1 ] );

		for( int i = 0; i <= size >> 1; ++i )
			profit = max( profit, **fish[ i ] - **nurish[ i*2 ] );
		printf( "%d\n", profit );
	}
}
