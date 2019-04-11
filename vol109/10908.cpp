#include<cstdio>

bool ok( char brd[ 100 ][ 101 ], int m, int n, int size, int h, int w )
{
	for( int i = m-size; i <= m+size; ++i )
		for( int j = n-size; j <= n+size; ++j )
			if( i >= h || i < 0 || j >= w || j < 0 || brd[ m ][ n ] != brd[ i ][ j ] )
				return false;
	return true;
}

int calc( char brd[ 100 ][ 101 ], int m, int n, int h, int w )
{
	int ans;
	for( ans = 1; ok( brd, m, n, ans, h, w ); ++ans );
	return 2*ans-1;
}

int main()
{
	int t, h, w, q, m, n;

	for( scanf( "%d", &t ); t--; )
	{
		char brd[ 100 ][ 101 ] = { 0 };
		scanf( "%d %d %d\n", &h, &w, &q );
		for( int i = 0; i < h; ++i )
			gets( brd[ i ] );
		for( printf( "%d %d %d\n", h, w, q ); q--; )
		{
			scanf( "%d %d", &m, &n );
			printf( "%d\n", calc( brd, m, n, h, w ) );
		}
	}
}
