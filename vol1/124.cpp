#include<cstdio>
#include<string>

void perm( int pending, int mask[], std::string s = "" )
{
	if( !pending )
		puts( s.c_str() );
	else
		for( int i = 0; i < 26; ++i )
			if( pending & 1 << i && !( pending & mask[ i ] ) )
				perm( pending ^ 1 << i, mask, s + char( 'a' + i ) );
}

int main()
{
	for( char s[ 1500 ], first = 1; gets( s ); )
	{
		if( first )
			first = 0;
		else
			puts( "" );

		int mask[ 26 ] = { 0 }, used = 0;
		for( int i = 0; !i || s[ i - 1 ]; i += 2 )
			used |= 1 << s[ i ] - 'a';
		gets( s );
		for( int i = 0; !i || s[ i - 1 ]; i += 4 )
			mask[ s[ i + 2 ] - 'a' ] |= 1 << s[ i ] - 'a';
		perm( used, mask );
	}
}
