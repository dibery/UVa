#include<cstdio>
#include<cmath>
const double PI=acos(-1);

double gcd( double a, double b ) { return fmod( a, b ) < 1e-12? b : gcd( b, fmod( a, b ) ); }

int main()
{
	int t, x, y;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &x, &y );
		double h = hypot( x, y ), theta = std::abs( h? asin( y / h ) : 0 ), g = gcd( PI, theta? theta : PI ), p = PI / g;
		if( log( h? h : 1 ) * p > log( 1 << 30 ) )
			puts( "TOO COMPLICATED" );
		else
			printf( "%.0f\n", p );
	}
}
