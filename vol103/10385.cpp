#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int dist, size, r; scanf( "%d", &dist ) == 1; )
	{
		double run[ 20 ] = { 0 }, cycle[ 20 ] = { 0 }, diff = -1, M = 10000;
		int at;

		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%lf %lf", run+i, cycle+i );

		for( r = 0; r <= dist*M; ++r ) // 0.0000 ~ D.0000
		{
			double time[ 20 ] = { 0 }, fast;

			for( int i = 0; i < size; ++i )
				time[ i ] = r / M / run[ i ] + ( dist*M - r ) / M / cycle[ i ];
			fast = *min_element( time, time+size-1 );
			if( diff <= fast - time[ size-1 ] + DBL_EPSILON )
				diff = fast - time[ size-1 ] + DBL_EPSILON, at = r;
		}
		if( diff += DBL_EPSILON < 0 )
			puts( "The cheater cannot win." );
		else
			printf( "The cheater can win by %.0f seconds with r = %.2fkm and k = %.2fkm.\n", diff*3600, at / M ( dist*M-at ) / M );
	}
}
