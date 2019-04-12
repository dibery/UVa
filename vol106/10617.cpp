#include<cstdio>

int main()
{
	int t, len;
	char s[ 61 ];

	for( scanf( "%d", &t ); t--; )
	{
		long long way[ 61 ][ 61 ] = { { 0 } };

		scanf( "%s", s );
		for( len = 0; s[ len ]; ++len )
			way[ len ][ len ] = 1;
		for( int span = 1; span < len; ++span )
			for( int begin = 0; begin + span < len; ++begin )
			{
				for( int end = begin + span; end >= begin; --end )
					if( s[ begin ] == s[ end ] )
						way[ begin ][ begin + span ] += way[ begin + 1 ][ end - 1 ] + 1;
				way[ begin ][ begin + span ] += way[ begin + 1 ][ begin + span ];
			}
		printf( "%lld\n", way[ 0 ][ len - 1 ] );
	}
}
