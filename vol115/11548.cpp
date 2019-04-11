#include<cstdio>

int main()
{
	int t, n;
	char s[ 70 ][ 71 ];

	for( scanf( "%d", &t ); t--; )
	{
		int score = 0;

		scanf( "%d", &n );
		for( int i = 0; i < n; ++i )
			scanf( "%s", s[ i ] );

		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j )
				if( i != j )
				{
					int match = 0;

					for( int p = 0; s[ i ][ p ]; ++p )
					{
						int trial = 0;

						for( int q = 0; s[ i ][ p + q ] && s[ j ][ q ]; ++q )
							trial += s[ i ][ p + q ] == s[ j ][ q ];
						if( trial > match )
							match = trial;
					}
					if( match > score )
						score = match;
				}
		printf ( "%d\n", score );
	}
}
