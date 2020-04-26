#include<bits/stdc++.h>
using namespace std;

int main()
{
	int init = strtol( "1111101111000110000100000", NULL, 2 ) * 25 + 12, dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 }, dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }, t;
	char brd[ 26 ] = { 0 };
	unordered_map<int,int> dist;
	queue<int> bfs;

	bfs.push( init );
	dist[ init ] = 0;
	for( int d = 0; d <= 10 && !bfs.empty(); bfs.pop() )
	{
		int f = bfs.front(), empty = f % 25, setting = f / 25, x = empty % 5, y = empty / 5;
		for( int i = 0; i < 25; ++i )
			brd[ i ] = setting & 1 << 24 - i? '1' : '0';
		for( int i = 0; i < 8; ++i )
			if( x + dx[ i ] < 5 && x + dx[ i ] >= 0 && y + dy[ i ] < 5 && y + dy[ i ] >= 0 )
			{
				int nx = x + dx[ i ], ny = y + dy[ i ], n = nx + ny * 5;
				swap( brd[ x + y * 5 ], brd[ n ] );
				int next = strtol( brd, NULL, 2 ) * 25 + n;
				if( dist.find( next ) == dist.end() )
					d = max( d, dist[ next ] = dist[ f ] + 1 ), bfs.push( next );
				swap( brd[ x + y * 5 ], brd[ n ] );
			}
	}

	for( scanf( "%d\n", &t ); t--; )
	{
		for( int i = 0; i < 5; ++i )
			gets( brd + 5 * i );
		int space = strchr( brd, ' ' ) - brd;
		brd[ space ] = '0';
		if( dist.find( strtol( brd, NULL, 2 ) * 25 + space ) == dist.end() )
			puts( "Unsolvable in less than 11 move(s)." );
		else
			printf( "Solvable in %d move(s).\n", dist[ strtol( brd, NULL, 2 ) * 25 + space ] );
	}
}
