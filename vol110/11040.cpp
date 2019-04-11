#include<cstdio>

int main()
{
	int t;

	for( scanf( "%d", &t ); t--; )
	{
		int brd[ 9 ][ 9 ] = { { 0 } };

		for( int i = 0; i < 9; i += 2 )
			for( int j = 0; j <= i; j += 2 )
				scanf( "%d", brd[ i ] + j );
		for( int i = 1; i < 9; i += 2 )
			brd[ 8 ][ i ] = ( brd[ 6 ][ i - 1 ] - brd[ 8 ][ i - 1 ] - brd[ 8 ][ i + 1 ] ) / 2;
		for( int i = 7; i >= 0; --i )
			for( int j = 0; j <= i; ++j )
				brd[ i ][ j ] = brd[ i + 1 ][ j ] + brd[ i + 1 ][ j + 1 ];
		for( int i = 0; i < 9; ++i )
			for( int j = 0; j <= i; ++j )
				printf( "%d%c", brd[ i ][ j ], j == i? '\n' : ' ' );
	}
}
