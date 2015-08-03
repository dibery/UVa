#include<cstdio>
#include<cstring>

int main()
{
	int man, link, t, val[ 10000 ], grp[ 10000 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &man, &link );
		int stat[ 10000 ] = { 0 }, zero[ 10000 ] = { 0 };

		for( int i = 0; i < man; ++i )
			scanf( "%d", val + i ), grp[ i ] = i;

		for( int a, b; link--; )
		{
			scanf( "%d %d", &a, &b );
			if( grp[ a ] != grp[ b ] )
				for( int i = 0, id = grp[ b ]; i < man; ++i )
					if( grp[ i ] == id )
						grp[ i ] = grp[ a ];
		}
		for( int i = 0; i < man; ++i )
			stat[ grp[ i ] ] += val[ i ];
		puts( memcmp( stat, zero, sizeof( int ) * man )? "IMPOSSIBLE" : "POSSIBLE" );
	}
}
