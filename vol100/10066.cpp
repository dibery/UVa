#include<cstring>
#include<cstdio>
#include<algorithm>
int field[ 1000 ][ 1000 ];

int main()
{
	int a[ 1001 ] = { 0 }, b[ 1001 ] = { 0 }, h, w, t = 0;

	while( scanf( "%d %d", &h, &w ) && h+w )
	{
		for( int i = 0; i < h; ++i )
			scanf( "%d", a+i );
		for( int i = 0; i < w; ++i )
			scanf( "%d", b+i );
		memset( field, 0, sizeof( field ) );
		for( int i = 0; i < w; ++i )
			field[ 0 ][ i ] = *a == b[ i ] || field[ 0 ][ i-1 ];
		for( int i = 1; i < h; ++i )
			field[ i ][ 0 ] = field[ i-1 ][ 0 ] || a[ i ] == *b;
		for( int i = 1; i < h; ++i )
			for( int j = 1; j < w; ++j )
				if( a[ i ] == b[ j ] )
					field[ i ][ j ] = field[ i-1 ][ j-1 ]+1;
				else
					field[ i ][ j ] = std::max( field[ i-1 ][ j ], field[ i ][ j-1 ] );
		printf( "Twin Towers #%d\nNumber of Tiles : %d\n\n", ++t, field[ h-1 ][ w-1 ] );
	}
}
