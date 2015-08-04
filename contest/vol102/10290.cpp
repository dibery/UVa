#include<cstdio>

long long prime[ 3000000 ], size;
bool notprime[ 30000001 ];

int main()
{
	prime[ size++ ] = 2;
	for( int i = 3; i <= 5477; i += 2 )
		if( !notprime[ i ] )
			for( int j = i*i; j < 30000001; j += 2*i )
				notprime[ j ] = true;
	for( int i = 3; i < 30000001; i += 2 )
		if( !notprime[ i ] )
			prime[ size++ ] = i;

	for( long long n; scanf( "%lld", &n ) == 1; )
	{
		if( n )
			n /= n & -n;
		long long ans = 1;

		for( int i = 1; i < size && prime[ i ] * prime[ i ] <= n; ++i )
			if( n % prime[ i ] == 0 )
			{
				int t = 0;
				while( n % prime[ i ] == 0 )
					n /= prime[ i ], ++t;
				ans *= t+1;
			}
		printf( "%lld\n", n > 1? ans << 1 : ans );
	}
}
