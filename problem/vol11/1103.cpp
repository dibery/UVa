#include<bits/stdc++.h>
using namespace std;

const int BLACK = 1, WHITE = 0;
int brd[ 200 ][ 200 ], h, w;
bool vis[ 200 ][ 200 ];

int todec( char c ) { return isalpha( c )? c - 'a' + 10 : c - '0'; }

void fill( int* p, int n )
{
	for( int i = 0; i < 4; ++i )
		*( p+i ) = n & 1 << 3-i? BLACK : WHITE;
}

void dfs_white( int x, int y )
{
	++vis[ x ][ y ];
	for( int i = x-1; i <= x+1; ++i )
		for( int j = y-1; j <= y+1; ++j )
			if( i >= 0 && i < h && j >= 0 && j < w && i == x ^ j == y && !vis[ i ][ j ] && brd[ i ][ j ] == WHITE )
				dfs_white( i, j );
}

int dfs( int x, int y )
{
	int white = 0;
	++vis[ x ][ y ];
	for( int i = x-1; i <= x+1; ++i )
		for( int j = y-1; j <= y+1; ++j )
			if( i >= 0 && i < h && j >= 0 && j < w && i == x ^ j == y && !vis[ i ][ j ] )
				if( brd[ i ][ j ] == BLACK )
					white += dfs( i, j );
				else
					dfs_white( i, j ), ++white;
	return white;
}

int main()
{
	int t = 0, mapping[] = { 1, 5, 3, 2, 4, 0 };
	char tmp[ 51 ], type[] = "ADJKSW";

	while( scanf( "%d %d\n", &h, &w ) && h )
	{
		int times[ 6 ] = { 0 };
		memset( brd, 0, sizeof( brd ) );
		memset( vis, 0, sizeof( vis ) );

		for( int i = 0; i < h; ++i )
		{
			gets( tmp );
			for( int j = 0; j < w; ++j )
				fill( brd[ i ] + j*4, todec( tmp[ j ] ) );
		}
		w <<= 2;

		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				if( ( !i || i == h-1 || !j || j == w-1 ) && !brd[ i ][ j ] )
					dfs_white( i, j );
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				if( brd[ i ][ j ] == BLACK && !vis[ i ][ j ] )
					++times[ dfs( i, j ) ];

		printf( "Case %d: ", ++t );
		for( int i = 0; i < 6; ++i )
			for( int j = 0; j < times[ mapping[ i ] ]; ++j )
				putchar( type[ i ] );
		puts( "" );
	}
}
