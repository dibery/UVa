#include<cstdio>
long long primes[ 170 ] = { 2 }, size = 1, ans[ 1000001 ], tot[ 1000001 ];

bool isp( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int totient( int n )
{
	int ret = n;

	for( int i = 0; i < size && primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
		{
			ret = ret / primes[ i ] * ( primes[ i ] - 1 );
			while( n % primes[ i ] == 0 )
				n /= primes[ i ];
			if( n > 1 )
				return ret * tot[ n ] / n;
		}
	if( n > 1 )
		ret = ret / n * ( n - 1 );
	return ret;
}

int main()
{
	for( int i = 3; i < 1000; i += 2 )
		if( isp( i ) )
			primes[ size++ ] = i;
	for( int i = 2; i <= 1000000; ++i )
		ans[ i ] = ans[ i - 1 ] + ( tot[ i ] = totient( i ) );
	for( int n; scanf( "%d", &n ) && n; printf( "%lld\n", ans[ n ] ) );
}
