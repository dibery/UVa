#include<cstdio>

void clear( char brd[ 30 ][ 30 ], int x, int y )
{
	brd[ x ][ y ] = '0';
	for( int i = x-1; i <= x+1; ++i )
		for( int j = y-1; j <= y+1; ++j )
			if( brd[ i ][ j ] == '1' )
				clear( brd, i, j );
}

int main()
{
	for( int size, t = 0; scanf( "%d", &size ) == 1; )
	{
		char brd[ 30 ][ 30 ] = { { 0 } };
		int has = 0;

		for( int i = 1; i <= size; ++i )
			scanf( "%s", brd[ i ] + 1 );
		for( int i = 1; i <= size; ++i )
			for( int j = 1; j <= size; ++j )
				if( brd[ i ][ j ] == '1' )
				{
					++has;
					clear( brd, i, j );
				}
		printf( "Image number %d contains %d war eagles.\n", ++t, has );
	}
}
