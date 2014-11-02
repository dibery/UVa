#include<cstdio>
#include<cstring>

int prime[ 500 ] = { 2 }, ps = 1, factor[ 1001 ][ 500 ];

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i < 1000; i += 2 )
		if( isp( i ) )
			prime[ ps++ ] = i;
	for( int i = 2; i <= 1000; ++i )
	{
		int t = i;
		for( int p = 0; p < ps && t != 1; ++p )
			while( t % prime[ p ] == 0 )
				++factor[ i ][ p ], t /= prime[ p ];
	}

	int t, in;
	char multi[ 30 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d%s", &in, multi );
		int has[ 500 ] = { 0 }, step = strlen( multi );
		for( int i = in; i > 0; i -= step )
			for( int p = 0; p < ps; ++p )
				has[ p ] += factor[ i ][ p ];
		long long int ans = 1;
		for( int i = 0; i < ps && ans <= 1e18; ++i )
			ans *= has[ i ] + 1;
		printf( ans <= 1e18? "Case %d: %lld\n" : "Case %d: Infinity\n", n, ans );
	}
}
