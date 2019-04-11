#include<cstdio>

long long primes[ 100000 ] = { 2 }, size = 1;

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	int t;
	long long n;

	for( int i = 3; i < 1e6; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;

	for( scanf( "%d", &t ); t-- && scanf( "%lld", &n ); )
	{
		long long sum = 1, copy = n;

		for( int i = 0; i < size && primes[ i ] * primes[ i ] <= n; ++i )
			if( n % primes[ i ] == 0 )
			{
				long long now = 1, div = 1;
				while( n % primes[ i ] == 0 )
					now += div *= primes[ i ], n /= primes[ i ];
				if( ( sum *= now ) > copy * 2 )
					break;
			}
		if( n > 1 && sum <= copy * 2 )
			sum *= ( n + 1 );
		sum -= copy;

		puts( sum < copy? "deficient" : sum == copy? "perfect" : "abundant" );
	}
}
