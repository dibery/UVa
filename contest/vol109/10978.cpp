#include<cstdio>
#include<cstring>

int main()
{
	int size;
	char suit[] = { "CDHS" }, face[] = { "A23456789TJQK" };

	while( scanf( "%d", &size ) && size )
	{
		int pos = -1, ins[ 52 ];
		char str[ 52 ][ 21 ] = { 0 }, card[ 52 ][ 3 ] = { 0 };
		memset( ins, -1, sizeof( ins ) );

		for( int i = 0; i < size; ++i )
			scanf( "%s %s", card[ i ], str[ i ] );
		for( int i = 0; i < size; ++i )
		{
			for( int len = strlen( str[ i ] ); len; pos = ( pos + 1 ) % size )
				if( ins[ (pos+1) % size ] == -1 )
					--len;
			ins[ pos ] = ( strchr( suit, card[ i ][ 1 ] ) - suit ) * 13 + ( strchr( face, card[ i ][ 0 ] ) - face );
		}
		for( int i = 0; i < size; ++i )
			printf( "%c%c%c", face[ ins[ i ] % 13 ], suit[ ins[ i ] / 13 ], i == size-1? '\n' : ' ' );
	}
}
