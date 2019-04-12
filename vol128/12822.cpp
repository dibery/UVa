#include<cstdio>

inline int tosec( int h, int m, int s ) { return h*3600 + m*60 + s; }

int main()
{
	int digit[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, score[ 1000 ] = { 6 }, t = 0;
	int pts, h, m, s, lh, lm, ls;
	char str[ 10 ], get[ 10 ];

	for( int i = 1; i < 1000; ++i )
	{
		sprintf( str, "%d", i );
		for( int j = 0; str[ j ]; ++j )
			score[ i ] += digit[ str[ j ] - '0' ];
	}

	while( scanf( "%*s %d:%d:%d", &lh, &lm, &ls ) == 3 )
	{
		int pow = 0, host = 0, guest = 0;
		while( scanf( "%s", str ) )
		{
			scanf( "%d:%d:%d", &h, &m, &s );
			if( *str == 'S' )
				scanf( "%s %d", get, &pts );
			pow += ( score[ host ] + score[ guest ] ) * ( tosec( h, m, s ) - tosec( lh, lm, ls ) );
			lh = h, lm = m, ls = s;
			if( *str == 'S' )
				( *get == 'h'? host : guest ) += pts;
			else
				break;
		}
		printf( "Case %d: %d\n", ++t, pow );
	}
}
