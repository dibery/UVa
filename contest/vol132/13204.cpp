#include<cstdio>

const int N = 1000001, MOD = 1000000007;
long long f[ N ] = { 1 }, ans[ N ];

int main()
{
	for( int i = 1; i < N; ++i )
		f[ i ] = f[ i - 1 ] * i % MOD;
	for( int n; scanf( "%d", &n ) == 1; )
		printf( "%lld\n", f[ n / 2 ] * f[ n / 2 ] % MOD * ( n % 2? n : 1 ) % MOD );
}
