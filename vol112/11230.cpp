#include<cstdio>
#include<cstring>

char s[ 100 ][ 101 ], t[ 100 ][ 101 ];

int main()
{
	for( int r, c, h, w; scanf( "%d %d %d %d", &r, &c, &h, &w ) && r; )
	{
		int ans = 0;
		memset( s, 0, sizeof( s ) );
		memset( t, 0, sizeof( t ) );
		for( int i = 0; i < r; ++i )
			scanf( "%s", s[ i ] );
		for( int i = 0; i < r; ++i )
			for( int j = 0; j < c; ++j )
				s[ i ][ j ] -= '0';
		for( int i = 0; i + h <= r; ++i )
			for( int j = 0; j + w <= c; ++j )
				if( t[ i ][ j ] != s[ i ][ j ] && ++ans )
					for( int m = i; m < i + h; ++m )
						for( int n = j; n < j + w; ++n )
							t[ m ][ n ] ^= 1;
		if( memcmp( s, t, sizeof( s ) ) )
			puts( "-1" );
		else
			printf( "%d\n", ans );
	}
}
