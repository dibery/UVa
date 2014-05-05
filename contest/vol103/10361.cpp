#include<cstdio>
#include<cstring>
void out( char* str, int begin, int end, bool LF = false )
{
	for( ; begin < end; ++begin )
		if( str[ begin ] != '<' && str[ begin ] != '>' )
			putchar( str[ begin ] );
	if( LF )
		puts( "" );
}

int main()
{
	int t, start[ 6 ] = { 0 };
	char str[ 2 ][ 200 ] = { { 0 } };

	for( scanf( "%d\n", &t ); t--; )
	{
		gets( *str ), gets( str[ 1 ] );
		for( int i = 2; i <= 5; ++i )
			start[ i ] = strchr( *str + start[ i-1 ], i % 2? '>' : '<' ) - *str + i % 2;
		out( *str, 0, strlen( *str ), true );
		out( str[ 1 ], 0, strchr( str[ 1 ], '.' ) - str[ 1 ] );
		out( *str, start[ 4 ], start[ 5 ] );
		out( *str, start[ 3 ], start[ 4 ] );
		out( *str, start[ 2 ], start[ 3 ] );
		out( *str, start[ 5 ], strlen( *str ), true );
	}
	return 0;
}