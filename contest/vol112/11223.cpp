#include<cstdio>
#include<cstring>
inline int max( int a, int b ) { return a > b? a : b; }
const char first[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?'!/()&:;=+-_\"@ ", second[][7] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-.", " " };

int main()
{
	char str[ 2001 ] = { 0 };
	int t;

	scanf( "%d\n", &t );
	for( int n = 1; n <= t; ++n )
	{
		printf( "Message #%d\n", n );
		for( char *p = gets( str ), *end; *p; p = *end? end + 1 : end )
		{
			end = strchr( p, ' ' );
			if( !end )
				end = p + strlen( p );
			for( int i = 0; i < 54; ++i )
				if( !strncmp( second[ i ], p, max( end - p, strlen( second[ i ] ) ) ) )
					putchar( first[ i ] );
		}
		puts( n == t? "" : "\n" );
	}
}
