#include<cstdio>
#include<algorithm>
using namespace std;

int bit1[ 1 << 15 ], bit[ 16 ][ 1 << 15 ];

long long calc( int bit1, int low, int high, int sbit = 0 )
{
	if( high < low )
		return 0;
	return low? bit[ bit1 ][ high ] - bit[ bit1 ][ low - 1 ] : bit[ bit1 ][ high ];
}

int main()
{
	for( int i = 1; i < 1 << 15; ++i )
		bit1[ i ] = 1 + bit1[ i ^ i & -i ];
	for( int i = 0; i < 16; ++i )
		for( int j = 0; j < 1 << 15; ++j )
			bit[ i ][ j ] = j? bit[ i ][ j - 1 ] + ( bit1[ j ] == i ) : !i;

	int t, hour, low, high;

	scanf( "%d", &t );
	for( int T = 1; T <= t && scanf( "%d %d %d", &hour, &low, &high ); ++T )
	{
		long long ans[ 31 ] = { 0 }, out = 0;
		int L = ( 1 << hour ) - high, H = ( 1 << hour ) - low;

		for( int i = 0; i <= H; i += 1 << 15 )
			for( int j = 0; j <= 15; ++j )
				ans[ bit1[ i >> 15 ] + j ] += calc( j, max( 0, L - i ), min( H - i, ( 1 << 15 ) - 1 ) );
		for( int i = 0; i <= hour; ++i )
			out += ans[ i ] << i;
		printf( "Case %d: %lld\n", T, out );
	}
}
