#include<cstdio>
#include<cmath>

int main()
{
	int t;
	double L, W, theta, H;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%lf %lf %lf", &L, &W, &theta );
		H = fmod( L * tan( theta /= 180 / M_PI ), W * 2 );
		if( H > W )
			H = W - H + W;
		printf( "%.3f\n", L / cos( theta ) / hypot( L, H ) );
	}
}
