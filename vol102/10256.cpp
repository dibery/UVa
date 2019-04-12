#include<bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
	Point() { scanf( "%d %d", &x, &y ); }
	Point( int a, int b ) { x = a; y = b; }
	bool operator< ( const Point& c ) { return x != c.x? x < c.x : y < c.y; }
	bool operator== ( const Point& c ) { return x == c.x && y == c.y; }
	bool operator!= ( const Point& c ) { return x != c.x || y != c.y; }
	int dist( const Point& c ) { return ( c.x - x ) * ( c.x - x ) + ( c.y - y ) * ( c.y - y ); }
};

struct line
{
	int x1, y1, x2, y2, dx, dy, A, B, C; // Ax+By=C
	line( Point& a, Point& b )
	{
		x1 = a.x;
		y1 = a.y;
		x2 = b.x;
		y2 = b.y;
		if( x1 > x2 || x1 == x2 && y1 > y2 )
			swap( x1, x2 ), swap( y1, y2 );
		dx = x2 - x1;
		dy = y2 - y1;
		A = -dy;
		B = dx;
		C = A*x1 + B*y1;
	}
	bool insersect( const line& L )
	{
		int D = A*L.B - B*L.A, Dx = C*L.B - B*L.C, Dy = A*L.C - C*L.A;
		if( D < 0 )
			D = -D, Dx = -Dx, Dy = -Dy;
		if( !D )
			if( Dx || Dy )
				return false;
			else
				return !( x2 < L.y1 || x1 > L.y2 );
		else
			return in( Dx, D*x2, D*x1 ) && in( Dy, D*y2, D*y1 ) && in( Dx, D*L.x2, D*L.x1 ) && in( Dy, D*L.y2, D*L.y1 );
	}
	bool in( int a, int b, int c ) { return a >= min( b, c ) && a <= max( b, c ); }
};

int cross( Point& a, Point& b, Point&c ) { return ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x ); }

void build( Point p[], int size, vector<Point>& ch )
{
	bool vis[ 1000 ] = { false };
	ch.push_back( *min_element( p, p+size ) );
	if( size == 1 )
		return;
	while( ch.size() == 1 || ch.front() != ch.back() )
	{
		int next = 0;
		for( int i = 1; i < size; ++i )
			if( !vis[ i ] )
			{
				int c = cross( ch.back(), p[ next ], p[ i ] );
				if( c > 0 || c == 0 && ch.back().dist( p[ i ] ) > ch.back().dist( p[ next ] ) )
					next = i;
			}
		ch.push_back( p[ next ] );
		++vis[ next ];
	}
}

bool ok( vector<Point>& ch1, vector<Point>& ch2 )
{
	for( size_t i = 0; i < ch1.size()-1; ++i )
		for( size_t j = 0; j < ch2.size()-1; ++j )
			if( line( ch1[ i ], ch1[ i+1 ] ).insersect( line( ch2[ j ], ch2[ j+1 ] ) ) )
				return false;
	int c = 0;
	Point f = ch2.front(), F = Point( 1e6, 1e6-1 );
	for( size_t i = 0; i < ch1.size()-1; ++i )
		if( line( ch1[ i ], ch1[ i+1 ] ).insersect( line( f, F ) ) )
			++c;
	return c % 2 == 0;
}

int main()
{
	freopen( ".test", "r", stdin );
	for( int s1, s2; scanf( "%d %d", &s1, &s2 ) && s1; )
	{
		Point p1[ s1 ], p2[ s2 ];
		vector<Point> ch1, ch2;

		build( p1, s1, ch1 );
		build( p2, s2, ch2 );
		/*
		for_each( ch1.begin(), ch1.end(), [] ( Point& p ) { printf( "Pair(%d,%d)\n", p.x, p.y ); } );
		puts("");
		for_each( ch2.begin(), ch2.end(), [] ( Point& p ) { printf( "Pair(%d,%d)\n", p.x, p.y ); } );
		*/
		puts( ok( ch1, ch2 )? "Yes" : "No" );
	}
}
