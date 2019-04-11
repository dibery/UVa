#include<cstdio>
#include<cstring>

const int N = 32;
bool brd[ 2 ][ N ][ N ];

char* proc( char* s, bool brd[ N ][ N ], int x1 = 0, int y1 = 0, int x2 = N, int y2 = N )
{
	if( *s == 'f' )
		for( int i = x1; i < x2; ++i )
			for( int j = y1; j < y2; ++j )
				brd[ i ][ j ] = true;
	else if( *s == 'p' )
	{
		char* tmp = proc( s + 1, brd, x1, y1 + y2 >> 1, x1 + x2 >> 1, y2 );
		tmp = proc( tmp, brd, x1, y1, x1 + x2 >> 1, y1 + y2 >> 1 );
		tmp = proc( tmp, brd, x1 + x2 >> 1, y1, x2, y1 + y2 >> 1 );
		return proc( tmp, brd, x1 + x2 >> 1, y1 + y2 >> 1, x2, y2 );
	}
	return s + 1;
}

int main()
{
	int t;
	char in[ 5000 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		memset( brd, false, sizeof( brd ) );
		proc( gets( in ), brd[ 0 ] );
		proc( gets( in ), brd[ 1 ] );

		int black = 0;
		for( int i = 0; i < N; ++i )
			for( int j = 0; j < N; ++j )
				black += brd[ 0 ][ i ][ j ] | brd[ 1 ][ i ][ j ];
		printf( "There are %d black pixels.\n", black );
	}
}
