#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T, len, seq[ 50 ], put[ 50 ], put2[ 50 ];

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d", &len ); ++t )
	{
		for( int i = 0; i < len; ++i )
			scanf( "%d", seq + i );
		sort( seq, seq + len );

		int pos = 0, pos2 = 0;

		if( len % 2 )
		{
			put[ pos++ ] = put2[ pos2++ ] = seq[ len / 2 ];
			for( int l = 0, u = len - 1; pos2 < len; )
			{
				put2[ pos2++ ] = seq[ l++ ];
				put2[ pos2++ ] = seq[ u-- ];
			}
			for( int l = 0, u = len - 1; pos < len; )
			{
				put[ pos++ ] = seq[ u-- ];
				put[ pos++ ] = seq[ l++ ];
			}
		}
		else
		{
			put[ pos++ ] = seq[ len / 2 - 1 ];
			put[ len - 1 ] = seq[ len / 2 ];
			for( int l = 0, u = len - 1; pos < len - 1; )
			{
				put[ pos++ ] = seq[ u-- ];
				put[ pos++ ] = seq[ l++ ];
			}
		}

		int diff = 0;

		for( int i = 1; i < len; ++i )
			diff += abs( put[ i ] - put[ i - 1 ] );
		if( len % 2 )
		{
			int diff2 = 0;
			for( int i = 1; i < len; ++i )
				diff2 += abs( put2[ i ] - put2[ i - 1 ] );
			diff = max( diff, diff2 );
		}
		printf( "Case %d: %d\n", t, diff );
	}
}
