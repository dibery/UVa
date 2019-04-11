#include<cstdio>
#include<cstring>
char mat[ 10000 ][ 10000 ], cmp[ 10000 ][ 10000 ];
void rotate( int size )
{
	char tmp[ size ][ size ];
	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			tmp[ j ][ size-i-1 ] = cmp[ i ][ j ];
	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			cmp[ i ][ j ] = tmp[ i ][ j ];
}

int main()
{
	int big, small;

	while( scanf( "%d %d", &big, &small ) && small )
	{
		for( int i = 0; i < big; ++i )
			scanf( "%s", mat[ i ] );
		for( int i = 0; i < small; ++i )
			scanf( "%s", cmp[ i ] );
		for( int i = 0; i < 4; ++i )
		{
			int match = 0;
			for( int m = 0; small+m <= big; ++m )
				for( int n = 0; small+n <= big; ++n )
				{
					bool ok = true;
					for( int p = 0; p < small && ok; ++p )
						for( int q = 0; q < small && ok; ++q )
							if( cmp[ p ][ q ] != mat[ m+p ][ n+q ] )
								ok = false;
					match += ok;
				}
			rotate( small );
			printf( "%d%c", match, i == 3? '\n' : ' ' );
		}
	}
}
