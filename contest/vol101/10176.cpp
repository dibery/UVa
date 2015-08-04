#include<cstdio>
#include<cstring>

int main()
{
	int mod[ 10000 ] = { 1 }, len = 0, r = 0;
	char c, all[ 10002 ];

	for( int i = 1; i < 10000; ++i )
		mod[ i ] = mod[ i-1 ] * 2 % 131071;

	while( ( c = getchar() ) != EOF )
		if( c == '#' )
		{
			for( int i = 0; i < len; ++i )
				r = ( r + ( all[ i ] - '0' ) * mod[ len-i ] ) % 131071;
			puts( r? "NO" : "YES" );
			r = len = 0;
		}
		else if( c != '\n' )
			all[ len++ ] = c;
}
