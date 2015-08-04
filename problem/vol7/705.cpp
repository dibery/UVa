#include<bits/stdc++.h>
#define N 200
using namespace std;

int dfs( char brd[ N ][ N ], bool vis[ N ][ N ], int i, int j, int h, int w )
{
	int ans = 1;
	vis[ i ][ j ] = true;

	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( m >= 0 && m < h && n >= 0 && n < w && !vis[ m ][ n ] && brd[ m ][ n ] == ' ' )
				if( m == i ^ n == j )
					ans += dfs( brd, vis, m, n, h, w );
				else if( m < i && n < j && ( brd[ m ][ j ] != '/' || brd[ i ][ n ] != '/' ) ||
						m < i && n > j && ( brd[ m ][ j ] == '/' || brd[ i ][ n ] == '/' ) ||
						m > i && n < j && ( brd[ m ][ j ] == '/' || brd[ i ][ n ] == '/' ) ||
						m > i && n > j && ( brd[ m ][ j ] != '/' || brd[ i ][ n ] != '/' ) )
					ans += dfs( brd, vis, m, n, h, w );
	return ans;
}

void see( char c[ N ][ N ], bool b[ N ][ N ], int h, int w )
{
	for( int i = 0; i < h; ++i, puts("") )
		for( int j = 0; j < w; ++j )
			putchar( b[ i ][ j ]? '*' : c[ i ][ j ] );
	puts("");
}

int main()
{
	for( int t = 1, h, w; scanf( "%d %d\n", &w, &h ) && h; ++t )
	{
		bool brd[ N ][ N ] = { { false } }, vis[ N ][ N ] = { { false } };
		char s[ 100 ][ 100 ], real[ N ][ N ] = { 0 };
		int ans = -1, cycle = 0;

		for( int i = 0; i < h; ++i )
		{
			gets( s[ i ] );
			for( int j = 0; j < w; ++j )
				if( s[ i ][ j ] == '/' )
					brd[ 2*i ][ 2*j + 1 ] = brd[ 2*i + 1 ][ 2*j ] = true;
				else
					brd[ 2*i ][ 2*j ] = brd[ 2*i + 1 ][ 2*j + 1 ] = true;
		}
		h *= 2, w *= 2;
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				real[ i ][ j ] = brd[ i ][ j ]? s[ i/2 ][ j/2 ] : ' ';

		//see( real, vis, h, w );

		for( int i = 0; i < h; ++i )
		{
			if( real[ i ][ 0 ] == ' ' && !vis[ i ][ 0 ] )
				dfs( real, vis, i, 0, h, w );
			if( real[ i ][ w-1 ] == ' ' && !vis[ i ][ w-1 ] )
				dfs( real, vis, i, w-1, h, w );
		}
		for( int i = 0; i < w; ++i )
		{
			if( real[ 0 ][ i ] == ' ' && !vis[ 0 ][ i ] )
				dfs( real, vis, 0, i, h, w );
			if( real[ h-1 ][ i ] == ' ' && !vis[ h-1 ][ i ] )
				dfs( real, vis, h-1, i, h, w );
		}
		//see( real, vis, h, w );

		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				if( !vis[ i ][ j ] && real[ i ][ j ] == ' ' )
					++cycle, ans = max( ans, dfs( real, vis, i, j, h, w ) );
		//see( real, vis, h, w );

		printf( "Maze #%d:\n", t );
		if( cycle )
			printf( "%d Cycles; the longest has length %d.\n\n", cycle, ans );
		else
			puts( "There are no cycles.\n" );
	}
}
