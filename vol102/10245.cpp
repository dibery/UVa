#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
inline double calc( double x, double y ) { return x*x + y*y; }
int main()
{
	double size, x[ 10000 ], y[ 10000 ];

	while( scanf( "%lf", &size ) && size )
	{
		double d = 400000000.0;
		for( int i = 0; i < size; ++i )
			scanf( "%lf %lf", x+i, y+i );
		for( int i = 0; i < size; ++i )
			for( int j = i+1; j < size; ++j )
				d = std::min( d, calc( x[ i ] - x[ j ], y[ i ] - y[ j ] ) );
		if( d <= 100000000 )
			printf( "%.4f\n", sqrt( d ) + 1e-12 );
		else
			puts( "INFINITY" );
	}
}
