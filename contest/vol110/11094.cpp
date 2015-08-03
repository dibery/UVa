#include<cstdio>
#include<algorithm>

int fill( char brd[ 22 ][ 22 ], int x, int y, int h, int w, char land )
{
	int size = 0;

	brd[ x ][ y ] = 0;
	for( int i = x-1; i <= x+1; ++i )
		for( int j = y-1; j <= y+1; ++j )
			if( i == x ^ j == y && brd[ i ][ ( j + w ) % w ] == land )
				size += fill( brd, i, ( j + w ) % w, h, w, land );

	return size + 1;
}

int main()
{
	for( int h, w, x, y; scanf( "%d %d", &h, &w ) == 2; )
	{
		char brd[ 22 ][ 22 ] = { { 0 } };

		for( int i = 1; i <= h; ++i )
			scanf( "%s", brd[ i ] );
		scanf( "%d %d", &x, &y );

		char land = brd[ ++x ][ y ];
		fill( brd, x, y, h, w, land );
		int ans = 0;

		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( brd[ i ][ j ] == land )
					ans = std::max( ans, fill( brd, i, j, h, w, land ) );
		printf( "%d\n", ans );
	}
}
