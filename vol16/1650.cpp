#include<bits/stdc++.h>

const long long MOD = 1000000007, N = 1001;
long long way[ N ][ N ], range_sum[ N ][ N ];

int main()
{
	for( char in[ N ]; scanf( "%s", in ) == 1; )
	{
		memset( way, 0, sizeof( way ) );
		memset( range_sum, 0, sizeof( range_sum ) );
		int len = strlen( in );

		**way = **range_sum = 1;
		for( int sum = 1; sum <= len; ++sum )
			for( int up = 0; up <= sum; ++up )
			{
				if( ( in[ len - sum ] == 'I' || in[ len - sum ] == '?' ) && up )
					way[ sum ][ up ] = range_sum[ sum - 1 ][ up - 1 ] % MOD;
				if( ( in[ len - sum ] == 'D' || in[ len - sum ] == '?' ) && up < sum )
					way[ sum ][ up ] += ( MOD + range_sum[ sum - 1 ][ sum - 1 ] - range_sum[ sum - 1 ][ up ] + way[ sum - 1 ][ up ] ) % MOD;
				range_sum[ sum ][ up ] = ( ( up? range_sum[ sum ][ up - 1 ] : 0 ) + way[ sum ][ up ] ) % MOD;
			}
		printf( "%lld\n", range_sum[ len ][ len ] );
	}
}
