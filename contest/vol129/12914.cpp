#include<cstdio>
const int MOD = 1711276033, N = 100001;

int main()
{
	long long sum[ N ] = { 0 }, fact[ N ] = { 1 };

	for( int i = 1; i < N; ++i )
	{
		sum[ i ] = i + sum[ i - 1 ];
		fact[ i ] = i * fact[ i - 1 ] % MOD;
	}

	for( int n; scanf( "%d", &n ) == 1; )
		for( long long i = 1, P = 1; i <= n; P = P * ( n + 1 - i++ ) % MOD )
			printf( "%lld%c", fact[ n-i ] * P % MOD * sum[ i ] % MOD, i == n? '\n' : ' ' );
}
