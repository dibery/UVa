#include<bits/stdc++.h>
using namespace std;

int price[ 200000 ], profit[ 200000 ][ 2 ];

int main()
{
	for( int day, cost; scanf( "%d %d", &day, &cost ) == 2; )
	{
		for( int i = 1; i <= day; ++i )
			scanf( "%d", price + day - i );
		memset( profit, 0, sizeof( profit ) );
		profit[ 0 ][ 1 ] = max( *price - cost, 0 );
		for( int i = 1; i < day; ++i )
		{
			profit[ i ][ 0 ] = max( profit[ i - 1 ][ 1 ] - price[ i ], profit[ i - 1 ][ 0 ] );
			profit[ i ][ 1 ] = max( profit[ i - 1 ][ 0 ] + price[ i ] - cost, profit[ i - 1 ][ 1 ] );
		}
		printf( "%d\n", *profit[ day - 1 ] );
	}
}
