#include<cstdio>
#include<algorithm>

int ans[ 501 ][ 500 ];

int main()
{
	int t, n, k;

	for( int i = 2; i <= 500; ++i )
		for( int j = 0; i + j <= 500; ++j )
		{
			ans[ i ][ j ] = ( 1 + j ) * i + ans[ i - 1 ][ j + 1 ];
			for( int k = 1; k < i; ++k )
				ans[ i ][ j ] = std::min( ans[ i ][ j ], ( 1 + j + k ) * i + ans[ k ][ j ] + ans[ i - k - 1 ][ j + k + 1 ] );
		}

	scanf( "%d", &t );
	for( int x = 1; x <= t && scanf( "%d %d", &n, &k ); ++x )
		printf( "Case %d: %d\n", x, ans[ n ][ k ] );
}
