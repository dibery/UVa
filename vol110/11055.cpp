#include<cstdio>

int main()
{
	int size, brd[ 1000 ][ 1000 ];

	while( scanf( "%d", &size ) && size )
	{
		bool ok = true;
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				scanf( "%d", brd[ i ] + j );
		for( int i = 0; i < size; ++i )
			for( int j = size-1; j >= 0; --j )
				brd[ i ][ j ] -= brd[ i ][ 0 ];
		for( int i = 1; i < size; ++i )
			for( int j = 0; j < size; ++j )
				ok &= brd[ i ][ j ] == brd[ 0 ][ j ];
		puts( ok? "homogeneous" : "not homogeneous" );
	}
}
