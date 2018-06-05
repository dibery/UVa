#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int N = 5000001, MOD = 1e8 + 7;
bool notprime[ N ];
long long prime[ N / 10 ] = { 2 }, size = 1;

int main()
{
	for( int i = 3; i * i < N; i += 2 )
		if( !notprime[ i ] )
			for( int j = i * i; j < N; j += 2 * i )
				notprime[ j ] = true;
	for( int i = 3; i < N; i += 2 )
		if( !notprime[ i ] )
			prime[ size++ ] = i;

	for( int n; scanf( "%d", &n ) && n; )
	{
		long long ans = 1;
		auto sum = [] ( long long n, long long d ) { return ( n + n % d ) * ( n / d + 1 ) / 2; };

		for( int i = 0; i < size && prime[ i ] <= n; ++i )
		{
			long long exp = 0;
			for( auto base = prime[ i ]; base <= n; base *= prime[ i ] )
				exp += sum( n - base + 1, base );
			ans = ans * ( ++exp % MOD ) % MOD;
		}

		printf( "%lld\n", ans );
	}
}
