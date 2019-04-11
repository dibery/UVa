#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
	int t, len;
	long long n;
	char sign[ 70 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %s %lld", &len, sign, &n ); puts( "" ) )
	{
		std::reverse( sign, sign + strlen( sign ) );
		if( !n )
			while( len-- )
				putchar( '0' );
		else
		{
			int ans[ 70 ] = { 0 };
			bool neg = n < 0, bad = false;

			if( neg )
				n = -n;
			for( int i = 0; i < 64 && !bad; ++i )
				if( n & 1ll << i )
					if( i >= len )
						bad = true;
					else if( ( sign[ i ] == 'n' ) ^ neg )
						if( ans[ i ] )
							--ans[ i ];
						else
							for( int j = i; !bad; ++j )
							{
								++ans[ j ];
								bad = j == len;
								if( ( sign[ j ] == 'p' ) ^ neg )
									break;
							}
					else if( ans[ i ] )
					{
						--ans[ i ];
						for( int j = i + 1; !bad; ++j )
						{
							++ans[ j ];
							bad = j == len;
							if( ( sign[ j ] == 'p' ) ^ neg )
								break;
						}
					}
					else
						++ans[ i ];

			if( bad )
				printf( "Impossible" );
			else
				while( len )
					printf( "%d", ans[ --len ] );
		}
	}
}
