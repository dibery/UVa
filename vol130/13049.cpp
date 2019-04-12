#include<cstdio>
#include<cstdlib>

inline int D( int a, int b ) { return abs( a - b ) < 5? abs( a - b ) : 10 - abs( a - b ); }

int main()
{
	int T, len;
	char a[ 101 ], b[ 101 ];

	scanf( "%d", &T );
	for( int n = 1; n <= T; ++n )
	{
		int dist = 0;
		scanf( "%d %s %s", &len, a, b );
		for( int i = 0; i < len; ++i )
			dist += D( a[ i ] - '0', b[ i ] - '0' );
		printf( "Case %d: %d\n", n, dist );
	}
}
