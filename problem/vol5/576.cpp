#include<cstdio>
#include<cstring>
char vowel[] = { "aeiouy" };

bool check( char* str, int count )
{
	while( *str )
	{
		while( *str && !strchr( vowel, *str ) )
			++str;
		if( *str )
			--count;
		while( *str == ' ' )
			++str;
		while( *str && strchr( vowel, *str ) )
			++str; 
		while( *str == ' ' )
			++str;
	}
	return !count;
}

int main()
{
	char str[ 3 ][ 200 ] = { { 0 } }, tmp[ 201 ] = { 0 };

	while( gets( tmp ) && strcmp( tmp, "e/o/i" ) )
	{
		sscanf( tmp, "%[^/]/%[^/]/%[^/]", str[ 0 ], str[ 1 ], str[ 2 ] );
		if( !check( str[ 0 ], 5 ) )
			puts( "1" );
		else if( !check( str[ 1 ], 7 ) )
			puts( "2" );
		else if( !check( str[ 2 ], 5 ) )
			puts( "3" );
		else
			puts( "Y" );
	}
}
