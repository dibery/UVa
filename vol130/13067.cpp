#include<cstdio>
const int N = 10000000;
long long primes[ N / 10 ] = { 2 }, size = 1;
bool notprime[ N ] = { true, true };

int main()
{
	for( int i = 3; i * i < N; i += 2 )
		if( !notprime[ i ] )
			for( int j = i * i; j < N; j += i * 2 )
				notprime[ j ] = true;
	for( int i = 3; i < N; i += 2 )
		if( !notprime[ i ] )
			primes[ size++ ] = i;
	for( long long n; scanf( "%lld", &n ) && n > 1; )
	{
		int ans = 0;
		for( int i = 0; i < size && primes[ i ] * primes[ i ] <= n; ++i )
			while( n % primes[ i ] == 0 )
				n /= primes[ i ], ++ans;
		printf( "%d\n", ans + ( n > 1 ) );
	}
}
