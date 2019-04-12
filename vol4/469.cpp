#include<cstdio>
#include<cstring>
#include<cctype>
const int N = 105;

int size( char brd[ N ][ N ], int x, int y )
{
	int ret = 1;
	
	brd[ x ][ y ] = 'L';
	for( int i = x - 1; i <= x + 1; ++i )
		for( int j = y - 1; j <= y + 1; ++j )
			if( brd[ i ][ j ] == 'W' )
				ret += size( brd, i, j );
	return ret;
}

int main()
{
	int t, x, y;
	char brd[ N ][ N ], s[ N ], tmp[ N ][ N ];

	for( scanf( "%d\n", &t ); t--; )
	{
		int h = 0, w = 0;
		memset( brd, 0, sizeof( brd ) );

		while( gets( s ) && isalpha( *s ) )
			strcpy( brd[ ++h ] + 1, s );
		do
		{
			memcpy( tmp, brd, sizeof( brd ) );
			sscanf( s, "%d %d", &x, &y );
			printf( "%d\n", size( tmp, x, y ) );
		}
		while( gets( s ) && *s );
		printf( t? "\n" : "" );
	}
}
