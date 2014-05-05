#include<cstdio>
#include<cmath>

int main()
{
	int t;
	double H, W, S;
	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%lf %lf %lf", &H, &W, &S );
		printf( "%.6lf%%\n", ( W*H - S * log( W / S * H ) - S ) / ( W*H ) * 100 + 1e-12 );
	}

	return 0;
}

