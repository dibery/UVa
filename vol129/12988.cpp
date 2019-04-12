#include<cstdio>

char brd[ 4 ][ 5 ];

bool ok( int r, int c )
{
	char C = brd[ r ][ c ];
	for( int i = 0; i < 4; ++i )
		if( brd[ r ][ i ] == C && i != c || brd[ i ][ c ] == C && i != r )
			return false;
	for( int i = r / 2 * 2; i <= r / 2 * 2 + 1; ++i )
		for( int j = c / 2 * 2; j <= c / 2 * 2 + 1; ++j )
			if( brd[ i ][ j ] == C && ( i != r || j != c ) )
				return false;
	return true;
}

bool fill( int pos = 0 )
{
	if( pos == 16 )
		return true;

	char& c = brd[ pos / 4 ][ pos % 4 ];

	if( c != '*' )
		return fill( pos + 1 );
	else
	{
		for( c = '1'; c <= '4'; ++c )
			if( ok( pos / 4, pos % 4 ) && fill( pos + 1 ) )
				return true;
		c = '*';
		return false;
	}
}

int main()
{
	int t;

	scanf( "%d", &t );
	for( int x = 1; x <= t; ++x )
	{
		for( int i = 0; i < 4; ++i )
			scanf( "%s", brd[ i ] );
		fill();
		printf( "Case #%d:\n", x );
		for( int i = 0; i < 4; ++i )
			puts( brd[ i ] );
	}
}
