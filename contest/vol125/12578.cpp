#include<cstdio>
const double pi = 3.141592653589793;

int main()
{
	int t;
	double n;
	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%lf", &n );
		printf( "%.2f %.2f\n", n * n / 25 * pi, n * 0.6 * n - n * n / 25 * pi );
	}

	return 0;
}
