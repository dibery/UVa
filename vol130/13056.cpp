#include<cstdio>
#include<cmath>

int main()
{
	int t, R, V;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &R, &V );
		printf( "Case %d: %.8f\n", n, M_PI / 2 * R / V );
	}
}
