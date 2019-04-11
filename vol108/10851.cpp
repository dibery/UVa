#include<cstdio>
#include<cstring>

int main()
{
	int t, len;
	char msg[ 10 ][ 81 ];

	for( scanf( "%d", &t ); t--; puts( "" ) )
	{
		for( int i = 0; i < 10; ++i )
			scanf( "%s", msg[ i ] );
		len = strlen( *msg );
		for( int i = 1; i < len - 1; ++i )
		{
			char c = 0;
			for( int j = 1; j <= 8; ++j )
				if( msg[ j ][ i ] == '\\' )
					c |= 1 << j - 1;
			putchar( c );
		}
	}
}
