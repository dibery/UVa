#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, month, shop;

	for( scanf( "%d", &t ); t--; )
	{
		int profit[ 100 ][ 50 ], earn[ 100 ][ 50 ] = { { 0 } }, cost[ 100 ][ 100 ] = { { 0 } }, ans = -1;

		scanf( "%d %d", &shop, &month );
		for( int i = 0; i < shop; ++i )
			for( int j = 0; j < month; ++j )
				scanf( "%d", earn[ i ] + j );
		for( int i = 0; i < shop; ++i )
			for( int j = 0; j < shop; ++j )
				scanf( "%d", cost[ i ] + j );
		memset( profit, -1, sizeof( profit ) );

		for( int i = 0; i < shop; ++i )
			*profit[ i ] = *earn[ i ];
		for( int i = 1; i < month; ++i )
			for( int j = 0; j < shop; ++j )
				for( int k = 0; k < shop; ++k )
					profit[ j ][ i ] = max( profit[ j ][ i ], profit[ k ][ i-1 ] + earn[ j ][ i ] - cost[ k ][ j ] );

		for( int i = 0; i < shop; ++i )
			ans = max( ans, profit[ i ][ month-1 ] );
		printf( "%d\n", ans );
	}
}
