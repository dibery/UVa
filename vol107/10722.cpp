// Should use bignum
#include<cstdio>

int zero[ 129 ][ 101 ], three[ 129 ][ 101 ], other[ 129 ][ 101 ], ans[ 129 ][ 101 ];

int main()
{
	for( int B = 4; B <= 128; ++B )
		for( int D = *ans[ B ] = *zero[ B ] = *three[ B ] = *other[ B ] = 1; D <= 100; ++D )
		{
			zero[ B ][ D ] = three[ B ][ D ] = ans[ B ][ D - 1 ];
			other[ B ][ D ] = ans[ B ][ D - 1 ] * ( B - 2 ) - three[ B ][ D - 1 ];
			ans[ B ][ D ] = zero[ B ][ D ] + three[ B ][ D ] + other[ B ][ D ];
		}

	for( int b, n; scanf( "%d %d", &b, &n ) && b; )
		printf( "%d\n", ans[ b ][ n ] );
}
