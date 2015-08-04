#include<cstdio>
#include<algorithm>
using namespace std;

class point
{
	public:
		point() { if( scanf( "%lf %lf", &x, &y ) == EOF ) eof = true; }
		point( double X, double Y ) { x = X; y = Y; }
		point( const point& c ) { *this = c; }
		bool operator== ( const point& c ) { return x == c.x && y == c.y; }
		bool operator!= ( const point& c ) { return !( *this == c ); }
		point operator+ ( const point& a ) { return point( x+a.x, y+a.y ); }
		point operator- ( const point& s ) { return point( x-s.x, y-s.y ); }
		point& operator= ( const point& a ) { x=a.x; y=a.y; return *this; }
		void print() { printf( "%.3f %.3f\n", x, y ); }
		double x, y;
		static bool eof;
};
bool point::eof = false;

int main()
{
	while( true )
	{
		point a, b, c, d;
		if( point::eof )
			break;
		if( a == c || a == d )
			swap( a, b );
		if( b != c )
			swap( c, d );
		( d + a - b ).print();
	}
}
