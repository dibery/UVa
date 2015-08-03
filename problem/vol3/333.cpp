#include<cstdio>
#include<cctype>

bool judge( int isbn[] )
{
	int partial[ 10 ] = { *isbn }, s2[ 10 ] = { *isbn };
	for( int i = 0; i < 9; ++i )
		if( isbn[ i ] == 10 )
			return false;
	for( int i = 1; i < 10; ++i )
		s2[ i ] = ( partial[ i ] = partial[ i-1 ] + isbn[ i ] ) + s2[ i-1 ];
	return s2[ 9 ] % 11 == 0;
}

int main()
{
	for( char s[ 99 ]; gets( s ); )
	{
		int use[ 99 ] = { 0 }, size = 0;

		for( int i = 0; s[ i ]; ++i )
			if( isdigit( s[ i ] ) )
				use[ size++ ] = s[ i ] - '0';
			else if( s[ i ] == 'X' )
				use[ size++ ] = 10;
		for( int i = 0; s[ i ]; ++i )
			if( !isspace( s[ i ] ) )
				putchar( s[ i ] );
		printf( " is %scorrect.\n", size == 10 && judge( use )? "" : "in" );
	}
}
