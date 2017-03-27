#include<cstdio>
#include<cmath>

struct point
{
	double x, y;
	point() { scanf( "%lf %lf", &x, &y ); }
};

point* create_pt()
{
	point *p = new point[ 6 ];
	for( int i = 0; i < 6; ++i )
		if( p[ i ].x || p[ i ].y )
			return p;
	delete[] p;
	return NULL;
}

double area( point p[ 3 ] )
{
	double a = hypot( p[ 0 ].x - p[ 1 ].x, p[ 0 ].y - p[ 1 ].y ),
				 b = hypot( p[ 1 ].x - p[ 2 ].x, p[ 1 ].y - p[ 2 ].y ),
				 c = hypot( p[ 0 ].x - p[ 2 ].x, p[ 0 ].y - p[ 2 ].y ),
				 s = ( a + b + c ) / 2;
	return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
}

double dx( point *a, point *b ) { return b->x - a->x; }
double dy( point *a, point *b ) { return b->y - a->y; }

int main()
{
	for( point *p; p = create_pt(); delete[] p )
	{
		double tri = area( p+3 ), base = hypot( dx( p, p+1 ), dy( p, p+1 ) ),
					 v = hypot( dx( p, p+2 ), dy( p, p+2 ) ),
					 theta = acos( ( dx( p, p+1 ) * dx( p, p+2 ) + dy( p, p+1 ) * dy( p, p+2 ) ) / v / base ),
					 h = tri / base,
					 ansx = dx( p, p+2 ) / v * h / sin( theta ) + p[ 0 ].x,
					 ansy = dy( p, p+2 ) / v * h / sin( theta ) + p[ 0 ].y;
		printf( "%.3f %.3f %.3f %.3f\n", ansx + dx( p, p+1 ), ansy + dy( p, p+1 ), ansx, ansy );
	}
}
