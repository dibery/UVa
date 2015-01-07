#include<cstdio>
#include<cmath>

int main()
{
	int size;
	bool first = true;
	char* format[] = { "%2d", "%3d", "%4d" };

	while( scanf( "%d", &size ) == 1 )
	{
		int brd[ 15 ][ 15 ] = { { 0 } }, y = size / 2, x = 0, use = log10( size*size );

		if( !first )
			puts( "" );
		first = false;
		printf( "n=%d, sum=%d\n", size, ( size*size + 1 ) / 2 * size );

		for( int n = 1; n <= size*size; ++n )
		{
			brd[ x ][ y ] = n;
			int tx = (x+size-1) % size, ty = (y+1) % size;
			if( brd[ tx ][ ty ] )
				tx = (x+1) % size, ty = y;
			x = tx, y = ty;
		}
		for( int i = 0; i < size; ++i )
		{
			for( int j = 0; j < size; ++j )
				printf( format[ use ], brd[ i ][ j ] );
			puts( "" );
		}
	}
}
