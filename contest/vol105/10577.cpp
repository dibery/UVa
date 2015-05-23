#include<bits/stdc++.h>
using namespace std;

int main()
{
  int v, t = 0;
  double x[ 3 ], y[ 3 ], dx[ 3 ], dy[ 3 ], xm[ 3 ], ym[ 3 ], ans[ 3 ], X[ 150 ], Y[ 150 ], D, Dx, Dy, Rx, Ry, theta, R;

  while( scanf( "%d", &v ) && v )
  {
	for( int i = 0; i < 3; ++i )
	  scanf( "%lf %lf", x+i, y+i );

	for( int i = 0; i < 3; ++i )
	{
	  dx[ i ] = x[ ( i + 1 ) % 3 ] - x[ i ];
	  dy[ i ] = y[ ( i + 1 ) % 3 ] - y[ i ];
	  xm[ i ] = ( x[ i ] + x[ ( i + 1 ) % 3 ] ) / 2;
	  ym[ i ] = ( y[ i ] + y[ ( i + 1 ) % 3 ] ) / 2;
	  ans[ i ] = dx[ i ] * xm[ i ] + dy[ i ] * ym[ i ];
	}

	D = dx[ 0 ] * dy[ 1 ] - dx[ 1 ] * dy[ 0 ];
	Dx = ans[ 0 ] * dy[ 1 ] - ans[ 1 ] * dy[ 0 ];
	Dy = dx[ 0 ] * ans[ 1 ] - dx[ 1 ] * ans[ 0 ];
	Rx = Dx / D;
	Ry = Dy / D;
	R = hypot( Rx - *x, Ry - *y );
	theta = acos( ( *x - Rx ) / R );
	for( int i = 0; i < v; ++i )
	{
	  X[ i ] = Rx + R * cos( 2 * M_PI / v * i + theta );
	  Y[ i ] = Ry + R * sin( 2 * M_PI / v * i + theta );
	}

	printf( "Polygon %d: %.3f\n", ++t, ( *max_element( X, X+v ) - *min_element( X, X+v ) ) * ( *max_element( Y, Y+v ) - *min_element( Y, Y+v ) ) );
  }
}
