#include<cstdio>
#include<cmath>
const double eps = 1e-12, end = 9999.9;
struct Rectangle
{
	double ulx, uly, drx, dry;
} rec[ 1000 ];
struct Circle
{
	double rx, ry, radius;
} cir[ 1000 ];
struct Triangle
{
	double x1, y1, x2, y2, x3, y3;
} tri[ 1000 ];
double cos( double x1, double y1, double x2, double y2, double x3, double y3 )
{
	double dx1 = x2 - x1, dy1 = y2 - y1, dx2 = x3 - x1, dy2 = y3 - y1;
	return ( dx1 * dx2 + dy1 * dy2 ) / hypot( dx1, dy1 ) / hypot( dx2, dy2 );
}

int main()
{
	char type, all[ 2000 ] = { 0 };
	int r = 0, c = 0, t = 0, a = 0, point = 0;
	double x, y;

	while( scanf( "%c", &type ) && type != '*' )
		if( type == 'r' && ( all[ a++ ] = type ) )
			scanf( "%lf %lf %lf %lf\n", &rec[ r ].ulx, &rec[ r ].uly, &rec[ r ].drx, &rec[ r ].dry ), ++r;
		else if( type == 'c' && ( all[ a++ ] = type ) )
			scanf( "%lf %lf %lf\n", &cir[ c ].rx, &cir[ c ].ry, &cir[ c ].radius ), ++c;
		else if( all[ a++ ] = type )
			scanf( "%lf %lf %lf %lf %lf %lf\n", &tri[ t ].x1, &tri[ t ].y1, &tri[ t ].x2, &tri[ t ].y2, &tri[ t ].x3, &tri[ t ].y3 ), ++t;
	while( scanf( "%lf %lf", &x, &y ) && std::abs( x-end ) > eps && std::abs( y-end ) > eps )
	{
		bool out = false;
		int tmpr = 0, tmpc = 0, tmpt = 0;
		++point;
		for( int i = 0; i < a; ++i )
		{
			if( all[ i ] == 'r' )
			{
				if( x > rec[ tmpr ].ulx && x < rec[ tmpr ].drx && y < rec[ tmpr ].uly && y > rec[ tmpr ].dry ) 
					printf( "Point %d is contained in figure %d\n", point, i+1 ), out = true;
				++tmpr;
			}
			else if( all[ i ] == 'c' )
			{
				if( hypot( x-cir[ tmpc ].rx, y-cir[ tmpc ].ry ) - cir[ tmpc ].radius < eps )
					printf( "Point %d is contained in figure %d\n", point, i+1 ), out = true;
				++tmpc;
			}
			else
			{
				bool a = cos( tri[ tmpt ].x1, tri[ tmpt ].y1, tri[ tmpt ].x2, tri[ tmpt ].y2, tri[ tmpt ].x3, tri[ tmpt ].y3 ) < cos( tri[ tmpt ].x1, tri[ tmpt ].y1, tri[ tmpt ].x2, tri[ tmpt ].y2, x, y );
				bool b = cos( tri[ tmpt ].x2, tri[ tmpt ].y2, tri[ tmpt ].x3, tri[ tmpt ].y3, tri[ tmpt ].x1, tri[ tmpt ].y1 ) < cos( tri[ tmpt ].x2, tri[ tmpt ].y2, tri[ tmpt ].x3, tri[ tmpt ].y3, x, y );
				bool c = cos( tri[ tmpt ].x3, tri[ tmpt ].y3, tri[ tmpt ].x1, tri[ tmpt ].y1, tri[ tmpt ].x2, tri[ tmpt ].y2 ) < cos( tri[ tmpt ].x3, tri[ tmpt ].y3, tri[ tmpt ].x1, tri[ tmpt ].y1, x, y );
				
				if( a && b && c )
					printf( "Point %d is contained in figure %d\n", point, i+1 ), out = true;
				++tmpt;
			}
		}
		if( !out )
			printf( "Point %d is not contained in any figure\n", point );
	}

	return 0;
}
