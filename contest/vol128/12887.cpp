#include<cstdio>

int main()
{
	long long ans[ 5001 ] = { 1 }, n;

	for( int i = 1; i <= 5000; ++i )
		for( int j = 0; j < i; ++j )
			ans[ i ] = ( ans[ i ] + ans[ j ] * ans[ i - j - 1 ] ) % 1000000007;
	for( scanf( "%*d" ); scanf( "%lld", &n ) == 1; )
		printf( "%lld\n", ans[ n ] );
}
