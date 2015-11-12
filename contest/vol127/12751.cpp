#include<cstdio>

int main()
{
	int t, N, K, X;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d", &N, &K, &X );
		printf( "Case %d: %d\n", n, N * ( N + 1 ) / 2 - ( 2 * X + K - 1 ) * K / 2 );
	}
}
