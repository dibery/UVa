#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cfloat>
const double R = 2.5000001, D = 5.000001, SQ = 6.2500001;

int main()
{
	int t;
	bool first = true;

	for( scanf( "%d\n", &t ); t--; )
	{
		double x[ 300 ], y[ 300 ];
		int size = 0, M = 1;

		for( char s[ 500 ]; gets( s ) && *s; ++size )
			sscanf( s, "%lf %lf", x + size, y + size );
		for( int i = 0; i < size; ++i )
			for( int j = i + 1; j < size; ++j )
				if( hypot( x[ i ] - x[ j ], y[ i ] - y[ j ] ) <= D )
				{
					int now = 0;
					double mx = ( x[ i ] + x[ j ] ) / 2, my = ( y[ i ] + y[ j ] ) / 2,
								 dx = x[ j ] - x[ i ], dy = y[ j ] - y[ i ],
								 A = dx * dx + dy * dy,
								 C = -SQ + ( mx - x[ i ] ) * ( mx - x[ i ] ) + ( my - y[ i ] ) * ( my - y[ i ] ),
								 t1 = sqrt( -4*A*C ) / A / 2,
								 cx1 = mx + dy * t1, cy1 = my - dx * t1, cx2 = mx - dy * t1, cy2 = my + dx * t1;

					for( int i = 0; i < size; ++i )
						now += hypot( cx1 - x[ i ], cy1 - y[ i ] ) <= R;
					if( now > M )
						M = now;
					now = 0;
					for( int i = 0; i < size; ++i )
						now += hypot( cx2 - x[ i ], cy2 - y[ i ] ) <= R;
					if( now > M )
						M = now;
				}

		if( first )
			first = false;
		else
			puts( "" );
		printf( "%d\n", M );
	}
}
