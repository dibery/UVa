#include<cstdio>
#include<cmath>
#include<cfloat>
#include<vector>
#include<algorithm>
using namespace std;

struct point
{
	double x, y;
	point( double X = 0, double Y = 0 ): x( X ), y( Y ) {}
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

	line( double x1, double y1, double x2, double y2 ) { *this = line( point( x1, y1 ), point( x2, y2 ) ); }

	point intersect( line L )
	{
		double d = A * L.B - B * L.A, dx = C * L.B - B * L.C, dy = A * L.C - C * L.A;
		return point( dx / d, dy / d );
	}

	bool cross( line L ) { return on( intersect( L ) ) && L.on( intersect( L ) ); }

	bool in( double a, double b, double c ) { return a >= min( b, c ) && a <= max( b, c ); }

	bool on( point p ) { return in( p.x, begin.x, end.x ) && in( p.y, begin.y, end.y ); }
};

int main()
{
	for( size_t size; scanf( "%lu", &size ) && size; )
	{
		vector<line> stick;
		bool covered[ 100000 ] = { false };

		for( double x1, y1, x2, y2; stick.size() < size; stick.push_back( line( x1, y1, x2, y2 ) ) )
			scanf( "%lf %lf %lf %lf", &x1, &y1, &x2, &y2 );
		for( int i = size - 1; i >= 0; --i )
				for( int j = i - 1; j >= 0; --j )
					if( !covered[ j ] && stick[ i ].cross( stick[ j ] ) )
						covered[ j ] = true;
		printf( "Top sticks: " );
		for( int i = 0; i < size; ++i )
			if( !covered[ i ] )
				printf( "%d%s", i + 1, i == size - 1? ".\n" : ", " ); 
	}
}
