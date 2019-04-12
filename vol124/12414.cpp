#include<cstdio>
#include<cstring>

int main()
{
	int C[ 51 ][ 51 ] = { { 0 } };
	char name[ 11 ];

	for( int i = 0; i <= 50; ++i )
		*C[ i ] = 1;
	for( int i = 1; i <= 50; ++i )
		for( int j = 1; j <= i; ++j )
			C[ i ][ j ] = ( C[ i-1 ][ j ] + C[ i-1 ][ j-1 ] ) % 10;

	while( scanf( "%s", name ) == 1 )
	{
		int ST, len = strlen( name );
		for( ST = 1; ST <= 10000; ++ST )
		{
			char buffer[ 51 ] = { 0 }, *p = buffer;
			for( int i = 0; i < len; ++i )
				sprintf( p, "%d", name[ i ] - 'A' + ST ), p += strlen( p );
			int calc[ 3 ] = { 0 }, L = p - buffer;
			for( int i = 0; i < 3; ++i )
				for( int j = 0; j <= L - 3; ++j )
					calc[ i ] = ( calc[ i ] + C[ L - 3 ][ j ] * ( buffer[ i + j ] - '0' ) ) % 10;
			if( calc[ 0 ] == 1 && calc[ 1 ] == 0 && calc[ 2 ] == 0 )
				break;
		}
		printf( ST <= 10000? "%d\n" : ":(\n", ST );
	}
}
