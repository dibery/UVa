#include<cstdio>
#include<cmath>

inline double to_rad( double deg ) { return acos( -1 ) * deg / 180; }

int main()
{
	double n, topx, topy, btmx, btmy, scale;

	while( scanf( "%lf", &n ) == 1 )
	{
		scale = sin( to_rad( 9 ) ) / sin( to_rad( 63 ) );
		topx = n/2;
		topy = tan( to_rad( 72 ) ) * topx;
		btmx = ( cos( to_rad( 108 ) ) + scale * cos( to_rad( 72 ) ) ) * n;
		btmy = ( sin( to_rad( 108 ) ) - scale * sin( to_rad( 72 ) ) ) * n;
		printf( "%.10f\n", hypot( topx - btmx, topy - btmy ) );
	}
}
