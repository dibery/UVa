#include<bits/stdc++.h>

int len( long long n )
{
	int r = 0;
	while( n )
		n >>= 1, ++r;
	return r;
}

char* str( char c, int n )
{
	static char s[ 100 ];
	memset( s, 0, 100 );
	memset( s, c, n );
	return s;
}

char* bin( long long n )
{
	static char s[ 100 ];
	memset( s, 0, 100 );
	for( int i = 0; n; n >>= 1 )
		s[ i++ ] = ( n & 1 ) + '0';
	std::reverse( s, s + strlen( s ) );
	return s;
}

int main()
{
	char a[ 31 ], b[ 31 ], all[ 100 ], format[ 63 ][ 9 ] = { { 0 } };
	bool first = true;

	for( int i = 0; i < 63; ++i )
		sprintf( format[ i ], "%%%ds\n", i );

	while( gets( all ) && strcmp( all, "0 0" ) )
	{
		sscanf( all, "%s %s", a, b );
		if( !first )
			puts( "" );
		else
			first = false;
		long long A = strtol( a, NULL, 2 ), B = strtol( b, NULL, 2 ), ans = A*B;
		int L = len( ans ), la = len( A ), lb = len( B );

		printf( format[ L ], a );
		printf( format[ L ], b );
		printf( format[ L ], str( '-', std::max( la, lb ) ) );
		for( int i = strlen( b ) - 1; i >= 0; --i )
			printf( format[ L - strlen( b ) + i + 1 ], b[ i ] == '0'? str( '0', la ) : a );
		puts( str( '-', L ) );
		puts( bin( ans ) );
	}
}
