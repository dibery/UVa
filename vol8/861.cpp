#include<bits/stdc++.h>

long long black[ 9 ][ 64 ], white[ 9 ][ 64 ], bit1[ 1 << 8 ];

void dfs_b( int lv, int now = 0, int main = 0, int inv = 0 ) // main/inverse diag
{
	if( now >= lv * lv )
	{
		++black[ lv ][ bit1[ main ] ];
		return;
	}
	if( ( now / lv + now % lv ) % 2 == 1 )
		return dfs_b( lv, now + 1, main, inv );
	dfs_b( lv, now + 1, main, inv );
	int I = 1 << ( now % lv + now / lv ) / 2, M = 1 << ( now % lv - now / lv ) / 2 + ( lv - 1 ) / 2;
	if( !( main & M ) && !( inv & I ) )
		dfs_b( lv, now + 1, main | M, inv | I );
}

void dfs_w( int lv, int now = 1, int main = 0, int inv = 0 ) // main/inverse diag
{
	if( ( now / lv + now % lv ) % 2 == 0 )
		return dfs_w( lv, now + 1, main, inv );
	if( now >= lv * lv )
	{
		++white[ lv ][ bit1[ main ] ];
		return;
	}
	dfs_w( lv, now + 1, main, inv );
	int M = 1 << ( now % lv - now / lv + 1 ) / 2 + ( lv - 1 ) / 2, I = 1 << ( now % lv + now / lv ) / 2;
	if( !( main & M ) && !( inv & I ) )
		dfs_w( lv, now + 1, main | M, inv | I );
}

int main()
{
	for( int i = 1; i < 1 << 8; ++i )
		bit1[ i ] = 1 + bit1[ i ^ i & -i ];
	for( int i = 1; i <= 8; ++i )
		dfs_b( i ), dfs_w( i );
	for( int size, bishop; scanf( "%d %d", &size, &bishop ) && size; )
	{
		long long ans = 0;
		for( int i = 0; i <= bishop; ++i )
			ans += black[ size ][ i ] * white[ size ][ bishop - i ];
		printf( "%lld\n", ans );
	}
}
