#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

double area( double a, double b, double c )
{
	double s = ( a + b + c ) / 2;
	return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
}

int main()
{
	int size, t;
	double len[ 10000 ] = { 0 };

	for( scanf( "%d", &t ); t--; )
	{
		double ans = 0;

		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%lf", len + i );
		sort( len, len + size );

		for( int i = size - 3; i >= 0; --i )
		{
			if( len[ i ] * len[ size - 2 ] / 2 <= ans )
				break;
			for( int j = size - 2; j > i; --j )
			{
				if( len[ i ] * len[ j ] / 2 <= ans )
					break;
				if( len[ j + 1 ] >= len[ i ] + len[ j ] || ( len[ j ] == len[ j-1 ] && j > i+1 ) )
					continue;

				double ideal = hypot( len[ i ], len[ j ] ), *p = lower_bound( len + j + 1, len + size, ideal );
				if( p < len + size && len[ i ] + len[ j ] > *p )
					ans = max( area( len[ i ], len[ j ], *p ), ans );
				if( p > len + j + 1 )
					ans = max( area( len[ i ], len[ j ], *--p ), ans );
			}
		}
		printf( "%.2f\n", ans );
	}
}
