#include<cstdio>

int main()
{
	const int L = 26, S = ( 1 + L ) * L / 2;
	int word[ L + 1 ][ S + 1 ][ L + 1 ] = { { { 0 } } }, t = 0; // L, S, letter

	for( int i = 0; i <= L; ++i )
		word[ 0 ][ 0 ][ i ] = 1;
	for( int l = 1; l <= L; ++l )
		for( int s = 1; s <= S; ++s )
			for( int c = 0; c < L; ++c )
				for( int first = c + 1; first <= L; ++first )
					if( s >= first * l )
						word[ l ][ s ][ c ] += word[ l - 1 ][ s - first ][ first ];
	for( int l, s; scanf( "%d %d", &l, &s ) && l + s; )
		printf( "Case %d: %d\n", ++t, s <= S && l <= L? *word[ l ][ s ] : 0 );
}
