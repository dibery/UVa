#include<cstdio>
#include<cstring>

int main()
{

	const char DV[] = { " `123qjlmfp/[]" "456.orsuyb;=\\" "789aehtdck-" "0zx,inwvg'" "~!@#QJLMFP?{}" "$%^>ORSUYB:+|" "&*(AEHTDCK_" ")ZX<INWVG\"" },
			  std[] = { " `1234567890-=" "qwertyuiop[]\\" "asdfghjkl;'" "zxcvbnm,./" "~!@#$%^&*()_+" "QWERTYUIOP{}|" "ASDFGHJKL:\"" "ZXCVBNM<>?" };

	for( char s[ 1001 ]; gets( s ); puts( "" ) )
		for( int i = 0; s[ i ]; ++i )
			putchar( DV[ strchr( std, s[ i ] ) - std ] );
}
