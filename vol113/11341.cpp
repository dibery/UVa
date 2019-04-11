#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
	int t, sub, time;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &sub, &time );
		int score[ 10 ][ 101 ] = { { 0 } }, study[ 10 ][ 101 ] = { { 0 } }, need[ 10 ] = { 0 };

		for( int i = 0; i < sub; ++i )
			for( int j = 1; j <= time; ++j )
				scanf( "%d", study[ i ] + j );
		for( int i = 0; i < sub; ++i )
			for( int j = 1; !need[ i ]; ++j )
				if( study[ i ][ j ] >= 5 || j == time )
					need[ i ] = j;

		for( int i = 0; i <= time; ++i )
			score[ 0 ][ i ] = i < *need? -1e7 : study[ 0 ][ i ];
		if( accumulate( need, need + sub, 0 ) <= time )
		{
			for( int i = 1; i < sub; ++i )
				for( int j = 0, k; j <= time; ++j )
					if( j < need[ i ] )
						score[ i ][ j ] = -1e7;
					else
						for( k = need[ i ]; k <= j; ++k )
							score[ i ][ j ] = max( score[ i ][ j ], study[ i ][ k ] + score[ i-1 ][ j-k ] );
			double ans = double( score[ sub-1 ][ time ] ) / sub + 1e-9;
			if( ans >= 5 )
				printf( "Maximal possible average mark - %.2f.\n", ans );
			else
				puts( "Peter, you shouldn't have played billiard that much." );
		}
		else
			puts( "Peter, you shouldn't have played billiard that much." );
	}
}
