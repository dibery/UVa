#include<cstdio>

inline int dist( int x, int y ) { return x*x + y*y; }

int main()
{
	int t, cx[ 100 ], cy[ 100 ], r[ 100 ], x, y, man, router;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &router, &man );
		for( int i = 0; i < router; ++i )
			scanf( "%d %d %d", cx+i, cy+i, r+i );
		printf( "Case %d:\n", n );
		for( int i = 0; i < man; ++i )
		{
			scanf( "%d %d", &x, &y );
			bool cover = false;
			for( int j = 0; j < router && !cover; ++j )
				cover |= dist( x - cx[ j ], y - cy[ j ] ) <= r[ j ] * r[ j ];
			puts( cover? "Yes" : "No" );
		}
	}
}
