#include<cstdio>
#include<cstring>

int main()
{
	const char *str = "aei", *var[ 3 ][ 6 ] = { { "o", "as", "a", "amos", "ais", "am" }, { "o", "es", "e", "emos", "eis", "em" }, { "o", "es", "e", "imos", "is", "em" } }, *noun[] = { "eu", "tu", "ele/ela", "n\xf3s", "v\xf3s", "eles/elas" };
	bool first = true;

	for( char por[ 32 ], eng[ 32 ]; scanf( "%s %s", por, eng ) == 2; )
	{
		int len = strlen( por );

		if( first )
			first = false;
		else
			puts( "" );

		printf( "%s (to %s)\n", por, eng );
		if( len > 1 && strchr( str, por[ len - 2 ] ) && por[ len - 1 ] == 'r' )
		{
			int offset = strchr( str, por[ len - 2 ] ) - str;

			por[ len - 2 ] = 0;
			for( int i = 0; i < 6; ++i )
				printf( "%-10s%s%s\n", noun[ i ], por, var[ offset ][ i ] );
		}
		else
			puts( "Unknown conjugation" );
	}
}
