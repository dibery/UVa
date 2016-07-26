#include<bits/stdc++.h>
using namespace std;

double angle( double x, double y )
{
	double a = acos( x / hypot( x, y ) );
	return y < 0? 2 * M_PI - a : a;
}

double arclen( double a, double b )
{
	return abs( a - b ) > M_PI? 2 * M_PI - abs( a - b ) : abs( a - b );
}

int main()
{
	int t;
	double A, B, C, x1, y1, x2, y2, r, a1, a2, l1, l2, touch[ 2 ][ 2 ];

	for( cin >> t; t-- && scanf( "%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r ); )
	{
		A = y1 - y2;
		B = x2 - x1;
		C = A * x1 + B * y1;
		a1 = angle( x1, y1 );
		a2 = angle( x2, y2 );
		l1 = sqrt( x1 * x1 + y1 * y1 - r * r );
		l2 = sqrt( x2 * x2 + y2 * y2 - r * r );
		touch[ 0 ][ 0 ] = a1 + atan( l1 / r );
		touch[ 0 ][ 1 ] = a1 - atan( l1 / r );
		touch[ 1 ][ 0 ] = a2 + atan( l2 / r );
		touch[ 1 ][ 1 ] = a2 - atan( l2 / r );
		for( int i = 0; i < 2; ++i )
			for( int j = 0; j < 2; ++j )
				if( touch[ i ][ j ] < 0 )
					touch[ i ][ j ] += 2 * M_PI;
				else if( touch[ i ][ j ] >= 2 * M_PI )
					touch[ i ][ j ] -= 2 * M_PI;
		if( abs( C ) / hypot( A, B ) >= r || ( B * x1 - A * y1 ) * ( B * x2 - A * y2 ) >= 0 )
			printf( "%.3f\n", hypot( A, B ) );
		else
		{
			double arc = DBL_MAX;
			for( int i = 0; i < 2; ++i )
				for( int j = 0; j < 2; ++j )
					arc = min( arc, arclen( touch[ 0 ][ i ], touch[ 1 ][ j ] ) );
			printf( "%.3f\n", l1 + l2 + arc * r );
		}
	}
}
