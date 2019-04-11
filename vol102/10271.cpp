#include<bits/stdc++.h>

int dp[ 1001 ][ 5001 ];
int sq( int n ) { return n * n; }

int main()
{
	int t, pair, stick, v[ 5001 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &pair, &stick ); )
	{
		pair += 8;
		for( int i = stick; i; --i )
			scanf( "%d", v + i );
		for( int p = 1; p <= pair; ++p )
			for( int s = p * 3; s <= stick; ++s )
				if( s == p * 3 )
					dp[ p ][ s ] = dp[ p - 1 ][ s - 2 ] + sq( v[ s - 1 ] - v[ s ] );
				else
					dp[ p ][ s ] = std::min( dp[ p ][ s - 1 ], sq( v[ s - 1 ] - v[ s ] ) + dp[ p - 1 ][ s - 2 ] );
		printf( "%d\n", dp[ pair ][ stick ] );
	}
}
