#include<bits/stdc++.h>
using namespace std;

struct point
{
	long long x, y;
	double angle;
	static bool proc;
	point() {}
	point( long long a, long long b ) { x = a; y = b; }
	bool operator< ( const point& c ) const
	{
		if( !proc )
			return y != c.y? y < c.y : x < c.x;
		else
			return angle < c.angle;
	}
	void calc( const point& p ) { angle = acos( ( x - p.x ) / hypot( x - p.x, y - p.y ) ); }
	point operator- ( const point& m ) { return point( x - m.x, y - m.y ); }
	point operator+ ( const point& m ) { return point( x + m.x, y + m.y ); }
} shape[ 100 ];
bool point::proc = false;

int main()
{
	for( int node; cin >> node && node >= 3; point::proc = false )
	{
		double area = 0, wx = 0, wy = 0;

		for( int i = 0; i < node; ++i )
			cin >> shape[ i ].x >> shape[ i ].y;
		sort( shape, shape + node );
		point::proc = true;

		for( int i = 1; i < node; ++i )
			shape[ i ].calc( *shape );
		sort( shape + 1, shape + node );

		for( int i = 2; i < node; ++i )
		{
			point a = shape[ i-1 ] - *shape, b = shape[ i ] - *shape, c = shape[ i ] + shape[ i-1 ] + *shape;
			double This = ( a.x * b.y - a.y * b.x ) / 2.0;

			area += This;
			wx += This * c.x / 3;
			wy += This * c.y / 3;
		}
		printf( "%.3f %.3f\n", wx / area + DBL_EPSILON, wy / area + DBL_EPSILON );
	}
}
