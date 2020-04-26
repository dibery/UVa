#include<bits/stdc++.h>
using namespace std; 

int test( int box, int man, int price[], int level )
{
	int cover[ 30 ] = { 0 };
	for( int i = 0; i < man; ++i )
		cover[ i ] = price[ i ] / level;
	if( accumulate( cover, cover + man, 0 ) < box )
		return -1;
	int knapsack[ 31 ][ 101 ];
	fill( knapsack[ 0 ], knapsack[ 31 ], INT_MAX / 2 );
	knapsack[ 0 ][ 0 ] = 0;
	for( int i = 1; i <= *cover; ++i )
		knapsack[ 0 ][ i ] = *price;
	for( int i = 1; i < man; ++i )
		for( int j = 0; j <= box; ++j )
			knapsack[ i ][ j ] = min( knapsack[ i - 1 ][ j ], price[ i ] + knapsack[ i - 1 ][ max( 0, j - cover[ i ] ) ] );
	return knapsack[ man - 1 ][ box ];
}

int main()
{
	for( int box, man, price[ 30 ]; scanf( "%d %d", &box, &man ) && box; )
	{
		for( int i = 0; i < man; ++i )
			scanf( "%d", price + i );
		int cost, level;
		for( level = *max_element( price, price + man ); level; --level )
			if( ( cost = test( box, man, price, level ) ) != -1 )
				break;
		printf( "%d %d\n", level, max( 0, cost ) );
	}
}
