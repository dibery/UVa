#include<cstdio>
#include<cmath>
#include<cfloat>

int main()
{
	for( double x1, x2, x3, y1, y2, y3; scanf( "%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3 ) == 6; )
	{
		// x^2 + y^2 + Dx + Ey + F -> solve DEF

		double A = x1 - x2, B = y1 - y2, C = -x1 * x1 - y1 * y1 + x2 * x2 + y2 * y2,
					 D = x2 - x3, E = y2 - y3, F = -x2 * x2 - y2 * y2 + x3 * x3 + y3 * y3,
					 del = A * E - B * D, delx = C * E - B * F, dely = A * F - C * D;
		if( std::abs( del ) < DBL_EPSILON )
			puts( "Impossible" );
		else
			printf( "%f %f\n", -delx / del / 2, -dely / del / 2 );
	}
}
