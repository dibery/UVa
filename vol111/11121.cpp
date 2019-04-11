#include<cstdio>

int main()
{
	int t, n;

	scanf( "%d", &t );
	for( int z = 1; z <= t && scanf( "%d", &n ) && printf( "Case #%d: ", z ); ++z, puts( "" ) )
	{
		if( !n )
			putchar( '0' );
		else
		{
			int ans[ 40 ] = { 0 }, p = 39;
			bool neg = n < 0;

			if( neg )
				n = -n;
			for( int i = 0; i < 31; ++i )
				if( n & 1 << i )
					if( i & 1 ^ neg )
						if( ans[ i ] )
							--ans[ i ];
						else
							++ans[ i ], ++ans[ i + 1 ];
					else if( ans[ i ] )
						--ans[ i ], ++ans[ i + 1 ], ++ans[ i + 2 ];
					else
						++ans[ i ];

			while( !ans[ --p ] );
			while( p >= 0 )
				printf( "%d", ans[ p-- ] );
		}
	}
}
