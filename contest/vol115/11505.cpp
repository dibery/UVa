#include<cstdio>
#include<cfloat>
#include<cmath>

int main()
{
	int t, n, l;
	char cmd[ 3 ];

	for( scanf( "%d", &t ); t--; )
	{
		int angle = 0;
		double x = 0, y = 0;

		for( scanf( "%d", &n ); n-- && scanf( "%s %d", cmd, &l ); )
			if( *cmd == 'f' )
				x += l * cos( angle * M_PI / 180 ), y += l * sin( angle * M_PI / 180 );
			else if( *cmd == 'b' )
				x -= l * cos( angle * M_PI / 180 ), y -= l * sin( angle * M_PI / 180 );
			else if( *cmd == 'l' )
				angle = ( angle + l ) % 360;
			else
				angle = ( angle - l + 360 ) % 360;
		printf( "%.0f\n", hypot( x, y ) + DBL_EPSILON );
	}
}
