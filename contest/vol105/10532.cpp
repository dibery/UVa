#include<cstdio>

int main()
{
	int item, query, num, t = 0;

	while( scanf( "%d %d", &item, &query ) && item )
	{
		int times[ 51 ] = { 0 }, size = 0;

		for( int i = 0; i < item; ++i )
			scanf( "%d", &num ), ++times[ num ];
		for( int i = 1; i <= item; ++i )
			if( times[ i ] )
				times[ ++size ] = times[ i ];
		for( printf( "Case %d:\n", ++t ); query--; )
		{
			unsigned long long int dp[ 51 ][ 51 ] = { { 1 } };
			scanf( "%d", &num );
			for( int i = 1; i <= size; ++i )
				for( int j = 0; j <= num; ++j )
					if( j )
						for( int k = 0; k <= times[ i ] && k <= j; ++k )
							dp[ i ][ j ] += dp[ i-1 ][ j-k ];
					else
						dp[ i ][ j ] = 1;
			printf( "%llu\n", dp[ size ][ num ] );
		}
	}
}
