#include<cstdio>

int main()
{
	for( double x1, y1, x2, y2, x, y, dx, dy; scanf( "%lf %lf %lf %lf", &x1, &y1, &x2, &y2 ) == 4; )
	{
		x = ( x1 + x2 ) / 2;
		y = ( y1 + y2 ) / 2;
		dx = x - x1;
		dy = y - y1;
		printf( "%.10f %.10f %.10f %.10f\n", x + dy, y - dx, x - dy, y + dx );
	}
}
