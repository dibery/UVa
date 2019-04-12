#include<bits/stdc++.h>
#define N 1005
#define E B+L-1
using namespace std;
long long int ans[ N ][ N ];

int main()
{
	long long int h[ N ], w[ N ], width;
	int a, b, c, d, qnt;

	while( scanf( "%d %d.%d", &qnt, &a, &b ) && ( width = a*10000 + b ) )
	{
		long long int sum[ 1000 ] = { 0 };

		for( int i = 1; i <= qnt; ++i )
		{
			scanf( "%d.%d %d.%d", &a, &b, &c, &d );
			h[ i ] = a*10000 + b;
			w[ i ] = c*10000 + d;
			sum[ i ] = sum[ i-1 ] + w[ i ];
		}

		for( int i = 1; i <= qnt; ++i )
			for( int j = i; j <= qnt; ++j )
				ans[ i ][ j ] = i == j? h[ i ] : LLONG_MAX >> 1;
		for( int L = 2; L <= qnt; ++L )
			for( int B = 1; E <= qnt; ++B )
				for( int M = B; M <= E; ++M )
					if( sum[ M ] - sum[ B - 1 ] <= width )
						ans[ B ][ E ] = min( ans[ B ][ E ], max( ans[ B ][ M-1 ], ans[ M ][ M ] ) + ans[ M+1 ][ E ] );
					else
						break;

		printf( "%d.%04d\n", int( ans[ 1 ][ qnt ] / 10000 ), int( ans[ 1 ][ qnt ] % 10000 ) );
	}
}
