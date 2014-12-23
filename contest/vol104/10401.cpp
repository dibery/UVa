#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

int trans( char c ) { return isdigit( c )? c-'0' : c-'A'+10; }

int main()
{
	char brd[ 16 ];

	while( gets( brd ) )
	{
		long long int sum[ 16 ][ 16 ] = { 0 }, ans = 0;
		int len = strlen( brd );

		if( brd[ len-1 ] == '?' )
			for( int i = 0; i < len; ++i )
				sum[ len-1 ][ i ] = 1;
		else
			sum[ len-1 ][ trans( brd[ len-1 ] ) - 1 ] = 1;
		for( int i = len-2; i >= 0; --i )
			if( brd[ i ] == '?' )
				for( int j = 0; j < len; ++j )
					for( int k = 0; k < len; ++k )
						if( abs( j-k ) > 1 )
							sum[ i ][ j ] += sum[ i+1 ][ k ];
						else;
			else
				for( int k = 0; k < len; ++k )
					if( abs( trans( brd[ i ] ) - 1 - k ) > 1 )
						sum[ i ][ trans( brd[ i ] ) - 1 ] += sum[ i+1 ][ k ];
		for( int i = 0; i < len; ++i )
			ans += sum[ 0 ][ i ];
		printf( "%lld\n", ans );
	}
}
