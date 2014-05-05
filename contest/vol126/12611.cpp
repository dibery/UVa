#include<cstdio>

int main()
{
	int t, n, r;
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d", &n );
		r = n >> 2;
		printf( "Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", i, -9*r, 6*r, 11*r, 6*r, 11*r, -6*r, -9*r, -6*r );
	}

	return 0;
}
