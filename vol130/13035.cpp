#include<cstdio>

int main()
{
	int t, M = 1000000007;
	long long n;

	scanf( "%d", &t );
	for( int T = 1; T <= t; ++T )
	{
		scanf( "%lld", &n );
		printf( "Case %d: ", T );
		if( n % 3 != 1 )
			printf( "%lld\n", ( n * ( n + 1 ) / 6 % M * ( 2 * n + 1 ) % M + n * ( n + 1 ) / 2 ) % M );
		else if( n % 2 )
			printf( "%lld\n", ( ( 2 * n + 1 ) * ( n + 1 ) / 6 % M * n % M + n * ( n + 1 ) / 2 ) % M );
		else
			printf( "%lld\n", ( ( 2 * n + 1 ) * n / 6 % M * ( n + 1 ) % M + n * ( n + 1 ) / 2 ) % M );
	}
}
