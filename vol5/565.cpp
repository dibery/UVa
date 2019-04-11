#include<cstdio>

bool ok( int sol, int like[], int dislike[], int size )
{
	for( int i = 0; i < size; ++i )
		if( !( sol & like[ i ] ) && !( ~sol & dislike[ i ] ) )
			return false;
	return true;
}

int main()
{
	char in[ 300 ];

	while( gets( in ) )
	{
		int size = 0, ans, like[ 10000 ] = { 0 }, dislike[ 10000 ] = { 0 };
		for( char *p = in; *p != ';'; p += 2 )
			( *p == '+'? like[ size ] : dislike[ size ] ) |= 1 << p[ 1 ] - 'A';
		for( ++size; gets( in ) && *in != '.'; ++size )
			for( char *p = in; *p != ';'; p += 2 )
				( *p == '+'? like[ size ] : dislike[ size ] ) |= 1 << p[ 1 ] - 'A';
		for( ans = 0; ans < 1 << 16 && !ok( ans, like, dislike, size ); ++ans );
		if( ans == 1 << 16 )
			puts( "No pizza can satisfy these requests." );
		else
		{
			printf( "Toppings: " );
			for( int i = 0; i < 16; ++i )
				if( ans & 1 << i )
					putchar( 'A' + i );
			puts( "" );
		}
	}
}
