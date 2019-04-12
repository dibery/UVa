#include<cstdio>
#include<cmath>

int main()
{
	int n, t = 0;
	double ploy, A, a, R, r;

	while( scanf( "%d %lf", &n, &ploy ) && n > 2 )
	{
		R = sqrt( ploy * 2 / n / sin( 2 * M_PI / n ) );
		A = R * R * M_PI;
		r = R * cos( M_PI / n );
		a = r * r * M_PI;
		printf( "Case %d: %.5f %.5f\n", ++t, A - ploy, ploy - a );
	}
}
