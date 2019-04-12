#include<cstdio>

inline bool line( char brd[][ 4 ], char c )
{
	for( int i = 0; i < 3; ++i )
		if( brd[ i ][ 0 ] == c && brd[ i ][ 1 ] == c && brd[ i ][ 2 ] == c ||
				brd[ 0 ][ i ] == c && brd[ 1 ][ i ] == c && brd[ 2 ][ i ] == c )
			return true;
	return brd[ 0 ][ 0 ] == c && brd[ 1 ][ 1 ] == c && brd[ 2 ][ 2 ] == c ||
		brd[ 0 ][ 2 ] == c && brd[ 1 ][ 1 ] == c && brd[ 2 ][ 0 ] == c;
}

int main()
{
	int t;
	char brd[ 3 ][ 4 ];

	for( scanf( "%d", &t ); t--; )
	{
		int o = 0, x = 0;

		scanf( "%s%s%s", brd[ 0 ], brd[ 1 ], brd[ 2 ] );
		for( int i = 0; i < 10; ++i )
			o += brd[ i / 3 ][ i % 3 ] == 'O', x += brd[ i / 3 ][ i % 3 ] == 'X';

		if( o > x || x - o > 1 )
			puts( "no" );
		else if( line( brd, 'O' ) && line( brd, 'X' ) )
			puts( "no" );
		else if( line( brd, 'O' ) && o < x || line( brd, 'X' ) && x == o )
			puts( "no" );
		else
			puts( "yes" );
	}
}
