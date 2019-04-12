#include<iostream>
#include<algorithm>
#include<cfloat>
#include<cmath>
using namespace std;

inline bool in( double a, double b, double c ) { return a >= b && a <= c; }

bool ok( int lx1, int ly1, int lx2, int ly2, int rx1, int ry1, int rx2, int ry2 )
{
	if( ry1 == ry2 ) // horizontal
	{
		if( ly1 < ry1 && ly2 < ry1 || ly1 > ry1 && ly2 > ry1 )
			return false;
		if( ly1 == ry1 && in( lx1, rx1, rx2 ) || ly2 == ry1 && in( lx2, rx1, rx2 ) )
			return true;
		if( ly1 != ly2 )
		{
			double r = abs( double( ry1 - ly1 ) / ( ly2 - ly1 ) ), p = lx1 + r * ( lx2 - lx1 );
			return in( p, rx1 - DBL_EPSILON, rx2 + DBL_EPSILON );
		}
		else if( ly1 == ry1 )
			return in( lx1, rx1, rx2 ) || in( lx2, rx1, rx2 );
	}
	else // vertical
	{
		if( lx1 < rx1 && lx2 < rx1 || lx1 > rx1 && lx2 > lx1 )
			return false;
		if( lx1 == rx1 && in( ly1, ry1, ry2 ) || lx2 == rx1 && in( ly2, ry1, ry2 ) )
			return true;
		if( lx1 != lx2 )
		{
			double r = abs( double( rx1 - lx1 ) / ( lx2 - lx1 ) ), p = ly1 + r * ( ly2 - ly1 );
			return in( p, ry1 - DBL_EPSILON, ry2 + DBL_EPSILON );
		}
		else if( lx1 == rx1 )
			return in( ly1, ry1, ry2 ) || in( ly2, ry1, ry2 );
	}
	return false;
}

int main()
{
	int t, lx1, lx2, ly1, ly2, rx1, rx2, ry1, ry2;

	for( cin >> t; t--; )
	{
		cin >> lx1 >> ly1 >> lx2 >> ly2 >> rx1 >> ry1 >> rx2 >> ry2;
		if( rx1 > rx2 )
			swap( rx1, rx2 );
		if( ry1 > ry2 )
			swap( ry1, ry2 );
		if( lx1 > lx2 || lx1 == lx2 && ly1 > ly2 )
			swap( lx1, lx2 ), swap( ly1, ly2 );
		if( in( lx1, rx1, rx2 ) && in( ly1, ry1, ry2 ) || in( lx2, rx1, rx2 ) && in( ly2, ry1, ry2 ) ||
				ok( lx1, ly1, lx2, ly2, rx1, ry1, rx1, ry2 ) ||
				ok( lx1, ly1, lx2, ly2, rx1, ry1, rx2, ry1 ) ||
				ok( lx1, ly1, lx2, ly2, rx1, ry2, rx2, ry2 ) ||
				ok( lx1, ly1, lx2, ly2, rx1, ry2, rx2, ry2 ) )
			puts( "T" );
		else
			puts( "F" );
	}
}
