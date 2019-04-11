#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int field[ 102 ][ 102 ];

int main()
{
	char a[ 101 ], b[ 101 ];
	int t = 0;

	while( gets( a ) && strcmp( a, "#" ) && gets( b ) )
	{
		int h = strlen( a ), w = strlen( b );
		if( !h || !w )
		{
			printf( "Case #%d: you can visit at most 0 cities.\n", ++t );
			continue;
		}
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
		printf( "Case #%d: you can visit at most %d cities.\n", ++t, field[ h-1 ][ w-1 ] );
	}
}
