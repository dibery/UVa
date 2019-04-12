#include<cstdio>
#include<utility>

typedef std::pair<double,double> point;

struct line
{
	double A, B, C;

	line( double a, double b, double c ): A( a ), B( b ), C( c ) {}

	point intersect( line L )
	{
		double d = A * L.B - B * L.A, dx = C * L.B - B * L.C, dy = A * L.C - C * L.A;
		return point( dx / d, dy / d );
	}
};

int main()
{
	for( int a, b, c, A, B, C; scanf( "%d%d%d%d%d%d", &a, &b, &c, &A, &B, &C ) && ( a || b || c || A || B || C ); )
	{
		if( a * B == b * A )
			puts( "No fixed point exists." );
		else
		{
			line L1( a, b, c ), L2( A, B, C );
			point p = L1.intersect( L2 );
			printf( "The fixed point is at %.2f %.2f.\n", p.first + 1e-9, p.second + 1e-9 );
		}
	}
}
