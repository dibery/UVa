#include<cstdio>
#include<cstring>
#include<algorithm>
bool ok( char* ball, int width, int len )
{
	char field[ 102 ][ 102 ];
	int way = 1, x = 1, y = 0, offx[] = { -1, 0, 1, 0 }, offy[] = { 0, 1, 0, -1 };	//nesw
	memset( field, -1, sizeof( field ) );
	for( int i = len/width; i; --i )
		for( int j = 1; j <= width; ++j )
			field[ i ][ j ] = 0;
	for( int i = 0; i < len; ++i )
		if( field[ x + offx[ way ] ][ y + offy[ way ] ] )
			way = ( way + 1 ) % 4, --i;
		else
			field[ x += offx[ way ] ][ y += offy[ way ] ] = ball[ i ];
	for( int i = 1; i <= width; ++i )
		for( int j = len/width; j; --j )
			if( field[ j ][ i ] != field[ 1 ][ i ] )
				return false;
	return true;
}

int main()
{
	int t;
	char ball[ 101 ] = { 0 };
	scanf( "%d", &t );

	for( int m = 1; m <= t; ++m )
	{
		scanf( "%s", ball );
		int len = strlen( ball ), ans = 200;
		for( int i = 2; i <= len / 2; ++i )
			if( len % i == 0 && ok( ball, i, len ) )
				ans = std::min( ans, i + len/i );
		printf( "Case %d: %d\n", m, ans == 200? -1 : ans );
	}
	return 0;
}
