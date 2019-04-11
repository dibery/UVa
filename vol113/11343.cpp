#include<cstdio>
#include<algorithm>
using namespace std;

struct LINE
{
	double xb, yb, xe, ye, ex, ey, ec; // x, y, and equation coefficients
	LINE()
	{
		scanf( "%lf %lf %lf %lf", &xb, &yb, &xe, &ye );
		ex = ye - yb;
		ey = xb - xe;
		ec = xb * ex + yb * ey;
	}

	bool in( double x, double y ) const
	{ return x >= min( xb, xe ) && x <= max( xb, xe ) && y >= min( yb, ye ) && y <= max( yb, ye ); }

	bool intersect( const LINE& l ) const
	{
		double d = ex * l.ey - ey * l.ex, dx = ec * l.ey - ey * l.ec, dy = ex * l.ec - ec * l.ex;
		if( d )
			return in( dx / d, dy / d ) && l.in( dx / d, dy / d );
		else if( dx || dy )
			return false;
		else
			return in( l.xb, l.yb ) || in( l.xe, l.ye ) || l.in( xb, yb ) || l.in( yb, ye );
	}
};

int main()
{
	int t, size;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &size );
		LINE* line = new LINE[ size ];
		int ans = 0;

		for( int i = 0; i < size; ++i )
		{
			bool iso = true;
			for( int j = 0; j < size && iso; ++j )
				if( i != j && line[ i ].intersect( line[ j ] ) )
					iso = false;
			ans += iso;
		}
		printf( "%d\n", ans );
	}
}
