#include<cstdio>
#include<cstring>
int judge( char* a, char* b )
{
	if( strcmp( a, b ) == 0 )
		return 0;
	int la = 0, lb = 0;
	for( int i = 0; a[ i ]; ++i )
		if( a[ i ] != ' ' )
			a[ la++ ] = a[ i ];
	for( int i = 0; b[ i ]; ++i )
		if( b[ i ] != ' ' )
			b[ lb++ ] = b[ i ];
	a[ la ] = b[ lb ] = 0;
	return strcmp( a, b )? 1 : 2;
}

int main()
{
	int t;
	char a[ 21 ], b[ 21 ], result[][ 20 ] = { "Yes", "Wrong Answer", "Output Format Error" };
	scanf( "%d\n", &t );

	for( int n = 1; n <= t; ++n )
	{
		gets( a );
		gets( b );
		printf( "Case %d: %s\n", n, result[ judge( a, b ) ] );
	}
}
