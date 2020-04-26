#include<bits/stdc++.h>
using namespace std;

long long sum[ 1001 ][ 1001 ];

int main()
{
	for( int len, mod, num[ 1000 ], ans; scanf( "%d %d", &len, &mod ) && len; )
	{
		for( int i = 0; i < len; ++i )
			scanf( "%d", num + i );
		memset( sum, 0, sizeof( sum ) );
		for( int i = len - 1; i >= 0; --i )
			sum[ 0 ][ i ] = ( sum[ 0 ][ i + 1 ] + num[ i ] ) % mod;
		for( int i = 1; i < len; ++i )
			for( int j = len - 1; j >= 0; --j )
				sum[ i ][ j ] = ( sum[ i ][ j + 1 ] + num[ j ] * sum[ i - 1 ][ j + 1 ] ) % mod;
		ans = **sum;
		for( int i = 1; i < len; ++i )
			ans = max( ( long long ) ans, sum[ i ][ 0 ] );
		printf( "%d\n", ans );
	}
}
