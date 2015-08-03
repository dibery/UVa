#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int primes[ 200 ] = { 2 }, p = 1, t, size[ 1000001 ] = { 0 };
	bool uniq[ 1000001 ];

	for( int i = 3; i < 1000; i += 2 )
	{
		bool is = true;

		for( int j = 0; primes[ j ] * primes[ j ] <= i && is; ++j )
			if( i % primes[ j ] == 0 )
				is = false;
		if( is )
			primes[ p++ ] = i;
	}

	fill( uniq, uniq + 1000001, true );
	for( int i = 1, j, n; i <= 1000000; ++i )
	{
		for( j = 0, n = i; j < p && primes[ j ] * primes[ j ] <= n; ++j )
			if( n % primes[ j ] == 0 )
			{
				if( n % ( primes[ j ] * primes[ j ] ) == 0 )
					uniq[ i ] = false;
				++size[ i ];
				while( n % primes[ j ] == 0 )
					n /= primes[ j ];
			}
		if( n != 1 )
			++size[ i ];
	}

	for( scanf( "%d", &t ); t--; )
	{
		long long a, b;
		scanf( "%lld %lld", &a, &b );
		if( a > b )
			swap( a, b );

		long long ans = a * b;
		for( int i = 2; i <= a; ++i )
			if( uniq[ i ] )
				ans += ( a / i ) * ( b / i ) * ( size[ i ] % 2? -1 : 1 );
		printf( "%lld\n", ans );
	}
}
