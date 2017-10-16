#include<cstdio>

int main()
{
	int t = 0, mask[] = { 11, 23, 38, 89, 186, 308, 200, 464, 416 };
	for( char s[ 201 ]; gets( s ); )
	{
		int brd[ 3 ][ 3 ] = { { 0 } };
		for( int i = 0; s[ i ]; ++i )
			for( int j = 0; j < 9; ++j )
				if( mask[ s[ i ] - 'a' ] & 1 << j )
					++brd[ j / 3 ][ j % 3 ] %= 10;
		printf( "Case #%d:\n", ++t );
		for( int i = 0; i < 3; ++i )
			printf( "%d %d %d\n", brd[ i ][ 0 ], brd[ i ][ 1 ], brd[ i ][ 2 ] );
	}
}
