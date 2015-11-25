#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
	int t, len;
	char s[ 101 ] = { 0 };

	for( scanf( "%d\n", &t ); t--; )
	{
		int times[ 26 ] = { 0 };

		len = strlen( gets( s ) );
		for( int i = 0; s[ i ]; ++i )
			++times[ s[ i ] - 'a' ];

		if( std::count_if( times, times + 26, [] ( int n ) { return n % 2 == 1; } ) > 1 )
			puts( "Impossible" );
		else
		{
			int ans = 0;
			for( int i = 0; i * 2 < len; ++i )
				if( times[ s[ i ] - 'a' ] == 1 )
					if( i == len / 2 )
						break;
					else
						std::swap( s[ i ], s[ i + 1 ] ), ++ans, --i;
				else
				{
					char *p = strrchr( s, s[ i ] );
					while( p[ 1 ] )
						std::swap( *p, p[ 1 ] ), ++p, ++ans;
					times[ s[ i ] - 'a' ] -= 2;
					*p = 0;
				}
			printf( "%d\n", ans );
		}
	}
}
