#include<cstdio>
#include<cstring>
bool ok( int* need, int* has )
{
	for( int i = 0; i < 26; ++i )
		if( need[ i ] > has[ i ] )
			return false;
	return true;
}

int main()
{
	char dict[ 1000 ][ 11 ] = { { 0 } }, tmp[ 11 ], in;
	int size = 0, ans = 0, freq[ 26 ] = { 0 }, need[ 1000 ][ 26 ] = { { 0 } };

	while( gets( tmp ) && *tmp != '#' )
		strcpy( dict[ size++ ], tmp );
	for( int i = 0; i < size; ++i )
		for( int j = 0; dict[ i ][ j ]; ++j )
			++need[ i ][ dict[ i ][ j ] - 'a' ];
	while( ( in = getchar() ) != '#' )
		if( in == '\n' )
		{
			for( int i = 0; i < size; ++i )
				ans += ok( need[ i ], freq );
			printf( "%d\n", ans );
			memset( freq, ans = 0, sizeof( freq ) );
		}
		else if( in != ' ' )
			++freq[ in-'a' ];
}
