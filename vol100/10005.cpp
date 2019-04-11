#include<cstdio>
#include<cmath>

bool pack( int x[], int y[], double r, int size, int i, int j, int k )
{
	int dx[ 3 ] = { x[ j ] - x[ i ], x[ k ] - x[ j ], x[ i ] - x[ k ] },
	    dy[ 3 ] = { y[ j ] - y[ i ], y[ k ] - y[ j ], y[ i ] - y[ k ] };
	double xm[ 2 ] = { ( x[ i ] + x[ j ] ) / 2.0, ( x[ j ] + x[ k ] ) / 2.0 },
	       ym[ 2 ] = { ( y[ i ] + y[ j ] ) / 2.0, ( y[ j ] + y[ k ] ) / 2.0 };

	if( dx[ 0 ] * dy[ 1 ] == dx[ 1 ] * dy[ 0 ] ) // co-linear, check with 2 points
		return false;
	for( int i = 0; i < 3; ++i )
		if( hypot( dx[ i ], dy[ i ] ) > r*2 + 1e-9 )
			return false;

	double ans[ 2 ] = { dx[ 0 ] * xm[ 0 ] + dy[ 0 ] * ym[ 0 ], dx[ 1 ] * xm[ 1 ] + dy[ 1 ] * ym[ 1 ] };
	double D = dx[ 0 ] * dy[ 1 ] - dx[ 1 ] * dy[ 0 ], Dx = ans[ 0 ] * dy[ 1 ] - ans[ 1 ] * dy[ 0 ], Dy = dx[ 0 ] * ans[ 1 ] - dx[ 1 ] * ans[ 0 ];
	double Rx = Dx / D, Ry = Dy / D;

	for( int i = 0; i < size; ++i )
		if( hypot( Rx - x[ i ], Ry - y[ i ] ) > r + 1e-9 )
			return false;
	return true;
}

bool pack( int x[], int y[], double r, int size, int i, int j )
{
	double Rx = ( x[ i ] + x[ j ] ) / 2.0, Ry = ( y[ i ] + y[ j ] ) / 2.0;

	if( hypot( x[ i ] - x[ j ], y[ i ] - y[ j ] ) > r*2 + 1e-9 )
		return false;
	for( int i = 0; i < size; ++i )
		if( hypot( Rx - x[ i ], Ry - y[ i ] ) > r + 1e-9 )
			return false;
	return true;
}

int main()
{
	for( int node, x[ 100 ], y[ 100 ]; scanf( "%d", &node ) && node; )
	{
		double r;
		bool ok = node == 1;

		for( int i = 0; i < node; ++i )
			scanf( "%d %d", x+i, y+i );
		scanf( "%lf", &r );

		for( int i = 0; i < node && !ok; ++i )
			for( int j = i+1; j < node && !ok; ++j )
			{
				ok |= pack( x, y, r, node, i, j );
				for( int k = j+1; k < node && !ok; ++k )
					ok |= pack( x, y, r, node, i, j, k );
			}
		puts( ok? "The polygon can be packed in the circle." : "There is no way of packing that polygon." );
	}
}
