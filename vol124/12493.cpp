#include<cstdio>

int main()
{
	bool notprime[ 46341 ] = { true, true };
	int primes[ 5000 ], size = 0;

	for( int i = 4; i < 46341; i += 2 )
		notprime[ i ] = true;
	for( int i = 3; i < 46341; i += 2 )
		if( !notprime[ i ] )
			for( int j = i * i; j < 46341; j += 2 * i )
				notprime[ j ] = true;
	for( int i = 0; i < 46341; ++i )
		if( !notprime[ i ] )
			primes[ size++ ] = i;

	for( int n, phi; scanf( "%d", &n ) == 1 && ( phi = n ); )
	{
		for( int i = 0; i < size; ++i )
			if( n % primes[ i ] == 0 )
			{
				phi = phi / primes[ i ] * ( primes[ i ] - 1 );
				while( n % primes[ i ] == 0 )
					n /= primes[ i ];
			}
		if( n > 1 )
			phi = phi / n * ( n - 1 );
		printf( "%d\n", phi / 2 );
	}
}
