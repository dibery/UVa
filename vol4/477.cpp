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

int main()
{
	char type, all[ 2000 ] = { 0 };
	int r = 0, c = 0, a = 0, point = 0;
	double x, y;

	while( scanf( "%c", &type ) && type != '*' )
		if( type == 'r' && ( all[ a++ ] = type ) )
			scanf( "%lf %lf %lf %lf\n", &rec[ r ].ulx, &rec[ r ].uly, &rec[ r ].drx, &rec[ r ].dry ), ++r;
		else if( all[ a++ ] = type )
			scanf( "%lf %lf %lf\n", &cir[ c ].rx, &cir[ c ].ry, &cir[ c ].radius ), ++c;
	while( scanf( "%lf %lf", &x, &y ) && std::abs( x-end ) > eps && std::abs( y-end ) > eps )
	{
		bool out = false;
		int tmpr = 0, tmpc = 0;
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
		}
		if( !out )
			printf( "Point %d is not contained in any figure\n", point );
	}

	return 0;
}
