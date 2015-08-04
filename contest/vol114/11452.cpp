#include<cstdio>
#include<cstring>

int main()
{
	int n, len, rep;
	char s[ 6000 ];

	for( scanf( "%d\n", &n ); n--; puts( "..." ) )
	{
		len = strlen( gets( s ) );
		for( rep = len / 2; rep > len / 3; --rep )
		{
			bool match = true;
			for( int i = rep; i < len; ++i )
				if( s[ i ] != s[ i % rep ] )
					match = false;
			if( match )
				break;
		}
		for( int i = 0; i < 8; ++i )
			putchar( s[ ( len + i ) % rep ] );
	}
}
