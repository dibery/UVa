#include<cstdio>

int main()
{
	char str[ 100 ];
	int size, count[ 1000 ][ 26 ] = { { 0 } };

	for( size = 0; gets( str ) && *str != '#'; ++size )
		for( int i = 0; str[ i ]; ++i )
			++count[ size ][ str[ i ] - 'a' ];
	while( gets( str ) && *str != '#' )
	{
		int ok = 0, cmp[ 26 ] = { 0 };
		for( int i = 0; str[ i ]; ++i )
			if( str[ i ] != ' ' )
				++cmp[ str[ i ] - 'a' ];
		for( int i = 0; i < size; ++i )
		{
			bool less = true;
			for( int j = 0; j < 26; ++j )
				less &= cmp[ j ] >= count[ i ][ j ];
			ok += less;
		}
		printf( "%d\n", ok );
	}
}
