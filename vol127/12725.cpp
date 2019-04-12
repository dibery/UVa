#include<cstdio>

int main()
{
	int t;
	double n, m, a, b;

	scanf( "%d", &t );
	for( int x = 1; x <= t && scanf( "%lf %lf %lf %lf", &n, &m, &a, &b ); ++x )
	{
		double diff = ( m * ( a + b ) - n * a ) / b;
		printf( "Case #%d: ", x );
		if( diff >= 0 && diff <= 10 )
			printf( "%.2f\n", diff );
		else
			puts( "Impossible" );
	}
}
