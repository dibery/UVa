#include<cstdio>
#include<cmath>

int main()
{
	int t, side, len, dx, dy;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		double x = 0, y = 0, angle = 0;

		scanf( "%d %d %d %d", &side, &len, &dx, &dy );
		printf( "Case #%d:\n%f %f\n", n, x + dx, y + dy );

		for( int i = 1; i < side; ++i )
		{
			x += cos( angle ) * len;
			y += sin( angle ) * len;
			printf( "%f %f\n", x, y );
			angle += 2 * M_PI / side;
		}
		printf( n == t? "" : "\n" );
	}
}
