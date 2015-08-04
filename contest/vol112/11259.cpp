#include<cstdio>

int main()
{
	int t, c[ 5 ] = { 0 }, query, qnt[ 5 ] = { 0 }, value;
	bool even_bit[ 16 ] = { true };

	for( int i = 1; i < 16; ++i )
		even_bit[ i ] = !even_bit[ i ^ ( i & -i ) ];
	
	for( scanf( "%d", &t ); t--; )
	{
		long long int dp[ 100001 ][ 5 ] = { { 1, 1, 1, 1, 1 } };

		scanf( "%d %d %d %d %d", c+1, c+2, c+3, c+4, &query );
		for( int v = 1; v <= 100000; ++v )
			for( int n = 1; n <= 4; ++n )
				if( v >= c[ n ] )
					dp[ v ][ n ] = dp[ v ][ n-1 ] + dp[ v - c[ n ] ][ n ];
				else
					dp[ v ][ n ] = dp[ v ][ n-1 ];

		while( query-- )
		{
			long long int ans = 0, mul[ 16 ] = { 0 };

			scanf( "%d %d %d %d %d", qnt+1, qnt+2, qnt+3, qnt+4, &value );
			for( int i = 1; i < 16; ++i )
				for( int j = 0; j < 4; ++j )
					if( i & 1 << j )
						mul[ i ] += c[ j+1 ] * ( qnt[ j+1 ] + 1 );

			for( int i = 0; i < 16; ++i )
				if( even_bit[ i ] && mul[ i ] <= value )
					ans += dp[ value - mul[ i ] ][ 4 ];
				else if( !even_bit[ i ] && mul[ i ] <= value )
					ans -= dp[ value - mul[ i ] ][ 4 ];
			printf( "%lld\n", ans );
		}
	}
}
