#include<cstdio>
#include<cmath>

int main()
{
	int t;
	double x, y, r;
	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%lf %lf %lf", &x, &y, &r );
		printf( "%.2f %.2f\n", r - hypot( x, y ), r + hypot( x, y ) );
	}

	return 0;
}
