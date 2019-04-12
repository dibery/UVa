#include<cstdio>
#include<cmath>
#include<cfloat>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
	double x, y;
	point( double X = 0, double Y = 0 ) { x = X; y = Y; }
	double dist( point p ) { return hypot( x - p.x, y - p.y ); }
};

struct line
{
	point begin, end;
	double A, B, C;
	line( point p1, point p2 ): begin( p1 ), end( p2 )
	{
		A = end.y - begin.y;
		B = begin.x - end.x;
		C = A * begin.x + B * begin.y;
	}
	point near( point p )
	{
		double d_beg = p.dist( begin ), d_end = p.dist( end );
		line ortho( p, point( p.x + end.y - begin.y, p.y - end.x + begin.x ) );
		point proj = intersect( ortho );
		if( in( proj.x, begin.x, end.x ) && in( proj.y, begin.y, end.y ) )
			return proj;
		return d_beg < d_end? begin : end;
	}
	point intersect( line L )
	{
		double d = A * L.B - B * L.A, dx = C * L.B - B * L.C, dy = A * L.C - C * L.A;
		return point( dx / d, dy / d );
	}
	bool in( double a, double b, double c ) { return a >= min( b, c ) && a <= max( b, c ); }
};

int main()
{
	for( double x, y; scanf( "%lf %lf", &x, &y ) == 2; )
	{
		point M( x, y ), loc;
		vector<point> seg;
		vector<line> rail;
		int size;
		double dist = 1e9;

		scanf( "%d", &size );
		for( int i = 0; i <= size; ++i )
		{
			scanf( "%lf %lf", &x, &y );
			seg.push_back( point( x, y ) );
			if( i )
				rail.push_back( line( seg[ i - 1 ], seg[ i ] ) );
		}
		for( auto& i: rail )
		{
			point p = i.near( M );
			if( dist > M.dist( p ) )
				dist = M.dist( p ), loc = p;
		}
		printf( "%.4f\n%.4f\n", loc.x + DBL_EPSILON, loc.y + DBL_EPSILON );
	}
}
