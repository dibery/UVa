#include<cstdio>
#include<algorithm>

int sum[ 10000000 ], one[ 10000000 ], prime[ 1000000 ] = { 2 }, size = 1, n, t;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i*i <= 3000000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i, one[ i ] = 1;
	for( int i = 2; i <= 3000000; ++i )
	{
		for( int j = 0; j < size && !one[ i ]; ++j )
			if( i % prime[ j ] == 0 )
				one[ i ] = 1 + one[ i / prime[ j ] ];
		if( !one[ i ] )
			one[ i ] = 1;
		sum[ i ] = sum[ i-1 ] + one[ i ];
	}
	for( scanf( "%d", &t ); t--; )
		scanf( "%d", &n ), printf( "%d\n", std::upper_bound( sum, sum+3000000, n ) - sum );
}
