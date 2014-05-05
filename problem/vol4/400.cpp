#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp( char* a, char* b ) { return strcmp( a, b ) < 0; }

int main()
{
	char str[ 100 ] = { 0 }, dash[] = { "------------------------------------------------------------" };
	int word;

	while( scanf( "%d", &word ) == 1 )
	{
		char *dict[ word ];
		int longest = 0;

		for( int i = 0; i < word; ++i )
		{
			scanf( "%s", str );
			dict[ i ] = strdup( str );
			longest = max( longest, (int)strlen( str ) );
		}
		sort( dict, dict+word, cmp );

		puts( dash );
		int col = max( 62 / ( longest+2 ), 1 ), row = ( word + col - 1 ) / col;
		for( int i = 0; i < row; ++i )
			for( int j = 0; j < col; ++j )
				if( row * j + i < word )
				{
					int len = strlen( dict[ row * j + i ] );
					printf( "%s", dict[ row * j + i ] );
					if( j != col-1 && row * j + i + row < word )
						for( int k = len; k < longest+2; ++k )
							putchar( ' ' );
					else
					{
						for( int k = len; k < longest; ++k )
							putchar( ' ' );
						if( row * j + i + row >= word && j != col-1 )
							printf( "  " );
						putchar( '\n' );
					}
				}
	}
	return 0;
}
