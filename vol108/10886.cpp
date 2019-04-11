#include<cstdio>
#include<cmath>

long long AND = ( 1ll << 32 ) - 1;
long double DIV = 1ll << 32, num[ 10000000 ];

int main()
{
	int T, n;
	unsigned long long seed;

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %llu", &n, &seed ); ++t )
	{
		long double mean = 0, var = 0;

		for( int i = 0; i < n; ++i )
		{
			seed >>= 16;
			seed &= AND;
			num[ i ] = ( seed *= seed ) / DIV;
			mean += num[ i ] / n;
		}

		for( int i = 0; i < n; ++i )
			var += ( num[ i ] - mean ) * ( num[ i ] - mean );
		printf( "Case #%d: %.5f\n", t, sqrt( var / ( long double ) n ) );
	}
}
