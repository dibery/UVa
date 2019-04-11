#include<cstdio>

int main()
{
	int T, a, b, c, m, n;

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d %d %d %d", &a, &b, &c, &m, &n ); ++t )
	{
		int mod[ 10000 ] = { 0 }, ans = 0;

		for( int i = 0, sum = 0; i < n; ++i )
			++mod[ ( sum += a ) % m ], a = ( a * b + c ) % m + 1;
		for( int i = 0; i < m; ++i )
			ans += mod[ i ] * ( mod[ i ] - 1 ) / 2;

		printf( "Case %d: %d\n", t, ans + *mod );
	}
}
