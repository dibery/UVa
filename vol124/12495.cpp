#include<bits/stdc++.h>

int single[ 11 ][ 1001 ][ 1001 ], sum[ 11 ][ 1001 ][ 1001 ];

int main()
{
	const int MOD = 1e9 + 7;
	for( int d = 1; d < 11; ++d )
	{
		for( int n = 1; n < 1001; ++n )
		{
			single[ d ][ 1 ][ n ] = n;
			( sum[ d ][ 1 ][ n ] = single[ d ][ 1 ][ n ] + sum[ d ][ 1 ][ n - 1 ] ) %= MOD;
		}
		for( int k = 2; k < 1001; ++k )
			for( int n = d; n < 1001; ++n )
			{
				single[ d ][ k ][ n ] = sum[ d ][ k - 1 ][ n - d ];
				( sum[ d ][ k ][ n ] = single[ d ][ k ][ n ] + sum[ d ][ k ][ n - 1 ] ) %= MOD;
			}
	}

	int T, n, k, d;
	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d %d", &n, &k, &d ); ++t )
	{
		int sum = 0;
		if( k == 1 )
			sum = n;
		else if( d <= n / 2 )
			for( int i = 0; i <= n - d; ++i )
				( sum += single[ d ][ k - 1 ][ n - i - d - std::max( d - i - 1, 0 ) ] ) %= MOD;
		printf( "Case %d: %d\n", t, sum );
	}
}
