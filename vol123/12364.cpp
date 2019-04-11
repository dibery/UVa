#include<cstdio>
#include<cstring>
#define A ".."
#define B "*."
#define C ".*"
#define D "**"

int main()
{
	const char map[ 10 ][ 3 ][ 3 ] = { { C, D, A }, { B, A, A }, { B, B, A }, { D, A, A }, { D, C, A }, { B, C, A }, { D, B, A }, { D, D, A }, { B, D, A }, { C, B, A } };

	for( int len; scanf( "%d%*c", &len ) && len; )
	{
		char cmd = getchar(), str[ 1000 ], S[ 100 ][ 3 ][ 3 ];

		if( cmd == 'S' )
		{
			scanf( "%s", str );
			int L = strlen( str );
			for( int i = 0; i < 3; ++i )
				for( int j = 0; j < L; ++j )
					printf( "%s%c", map[ str[ j ] - '0' ][ i ], j == L-1? '\n' : ' ' );
		}
		else
		{
			for( int i = 0; i < 3; ++i )
				for( int j = 0; j < len; ++j )
					scanf( "%s", S[ j ][ i ] );
			for( int i = 0; i < len; ++i )
				for( int j = 0; j < 10; ++j )
					if( !strcmp( S[ i ][ 0 ], map[ j ][ 0 ] ) && !strcmp( S[ i ][ 1 ], map[ j ][ 1 ] ) && !strcmp( S[ i ][ 2 ], map[ j ][ 2 ] ) )
						printf( "%d", j );
			puts( "" );
		}
	}
}
