#include<bits/stdc++.h>
using namespace std;

bool connected( bool[105][105], int, int ), size( int[105][105], bool[105][105], int, int ), edge( bool[105][105], int, int ), sub( bool[105][105], int, int );
int dfs( int[105][105], bool[105][105], bool[105][105], int, int, int, int );
void dfs( bool[105][105], bool[105][105], int, int, int, int );
void dfs( bool[105][105], int, int, int, int, bool[105][105] );

int main()
{
	int h, w, filled, t;
	char stat[ 105 ] = { 0 };

	for( scanf( "%d", &t ); t--; )
	{
		int brd[ 105 ][ 105 ] = { { 0 } }, count = 0;
		bool shade[ 105 ][ 105 ] = { { false } }, ok = true;

		scanf( "%d %d %d\n", &h, &w, &filled );
		for( int i = 0, x, y, n; i < filled; ++i )
			scanf( "%d %d %d\n", &x, &y, &n ), count += brd[ x ][ y ] = n;
		for( int i = 0; i < h; ++i )
		{
			scanf( "%s", stat );
			for( int j = 0; stat[ j ]; ++j )
				if( stat[ j ] == '#' )
					shade[ i ][ j ] = true;
				else
					--count;
		}

		ok &= !count && connected( shade, h, w ) && size( brd, shade, h, w ) && edge( shade, h, w ) && sub( shade, h, w );

		puts( ok? "solved" : "not solved" );
	}
}

bool connected( bool shade[ 105 ][ 105 ], int h, int w )
{
	bool vis[ 105 ][ 105 ] = { { false } };

	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; ++j )
			if( shade[ i ][ j ] )
				dfs( shade, vis, i, j, h, w ), i = h;
	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; ++j )
			if( shade[ i ][ j ] && !vis[ i ][ j ] )
				return false;
	return true;
}

void dfs( bool shade[ 105 ][ 105 ], bool vis[ 105 ][ 105 ], int m, int n, int h, int w )
{
	vis[ m ][ n ] = true;
	for( int i = m-1; i <= m+1; ++i )
		for( int j = n-1; j <= n+1; ++j )
			if( i >= 0 && i < h && j >= 0 && j < w && !vis[ i ][ j ] && shade[ i ][ j ] && i == m ^ j == n )
				dfs( shade, vis, i, j, h, w );
}

bool size( int brd[ 105 ][ 105 ], bool shade[ 105 ][ 105 ], int h, int w )
{
	bool vis[ 105 ][ 105 ] = { { false } };

	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; ++j )
			if( brd[ i ][ j ] )
				if( shade[ i ][ j ] || dfs( brd, shade, vis, i, j, h, w ) != brd[ i ][ j ] )
					return false;
	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; ++j )
			if( !shade[ i ][ j ] && !vis[ i ][ j ] )
				return false;
	return true;
}

int dfs( int brd[ 105 ][ 105 ], bool shade[ 105 ][ 105 ], bool vis[ 105 ][ 105 ], int m, int n, int h, int w )
{
	int ans = 1;
	vis[ m ][ n ] = true;
	for( int i = m-1; i <= m+1; ++i )
		for( int j = n-1; j <= n+1; ++j )
			if( i >= 0 && i < h && j >= 0 && j < w && !vis[ i ][ j ] && !shade[ i ][ j ] && i == m ^ j == n )
				ans += dfs( brd, shade, vis, i, j, h, w );
	return ans;
}

bool edge( bool shade[ 105 ][ 105 ], int h, int w )
{
	bool vis[ 105 ][ 105 ] = { { false } };

	for( int i = 0; i < h; i += h-1 )
		for( int j = 0; j < w; ++j )
			if( !shade[ i ][ j ] && !vis[ i ][ j ] )
				dfs( shade, i, j, h, w, vis );
	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; j += w-1 )
			if( !shade[ i ][ j ] && !vis[ i ][ j ] )
				dfs( shade, i, j, h, w, vis );
	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; ++j )
			if( !shade[ i ][ j ] && !vis[ i ][ j ] )
				return false;
	return true;
}

void dfs( bool shade[ 105 ][ 105 ], int m, int n, int h, int w, bool vis[ 105 ][ 105 ] )
{
	vis[ m ][ n ] = true;
	for( int i = m-1; i <= m+1; ++i )
		for( int j = n-1; j <= n+1; ++j )
			if( i >= 0 && i < h && j >= 0 && j < w && !shade[ i ][ j ] && !vis[ i ][ j ] )
				dfs( shade, i, j, h, w, vis );
}

bool sub( bool shade[ 105 ][ 105 ], int h, int w )
{
	for( int i = 0; i < h-1; ++i )
		for( int j = 0; j < w-1; ++j )
			if( shade[ i ][ j ] && shade[ i ][ j+1 ] && shade[ i+1 ][ j ] && shade[ i+1 ][ j+1 ] )
				return false;
	return true;
}
