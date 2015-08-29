#include<cstdio>
#include<cmath>

int main()
{
	for( double R, N, P, A, r, E, I; scanf( "%lf %lf", &R, &N ) == 2; )
	{
		P = R / ( sin( M_PI / N ) + 1 );
		r = R - P;
		A = P * P * sin( 2 * M_PI / N ) / 2 * N;
		I = A - r * r * M_PI / 2 * ( N - 2 );
		E = R * R * M_PI - r * r * M_PI * N - I;
		if( N > 1 )
			printf( "%.10f %.10f %.10f\n", r, I, E );
		else
			printf( "%.10f %.10f %.10f\n", R, 0., 0. );
	}
}
