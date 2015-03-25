#include<cstdio>
#include<cstring>
#include<algorithm>
#define XR min( j+i+D, H+W )
#define XL max( j+i-D-1, 0 )
#define YR min( j-i+H+D, H+W )
#define YL max( j-i+H-D-1, 0 )
using namespace std;

int brd[ 2001 ][ 2001 ];

int main()
{
	int H, W, S, Q, D, T = 0;

	while( scanf( "%d %d %d %d", &H, &W, &S, &Q ) && H )
	{
		memset( brd, 0, sizeof( brd ) );

		for( int x, y; S--; ++brd[ x+y ][ y-x + H ] )
			scanf( "%d %d", &x, &y );
		for( int i = 1; i <= H+W; ++i )
			for( int j = 1; j <= H+W; ++j )
				brd[ i ][ j ] += brd[ i-1 ][ j ] + brd[ i ][ j-1 ] - brd[ i-1 ][ j-1 ];

		printf( "Case %d:\n", ++T );
		for( int ans = 0, I = 1, J = 1; Q--; ans = 0, I = J = 1 )
		{
			scanf( "%d", &D );
			for( int j = 1; j <= W; ++j )
				for( int i = 1; i <= H; ++i )
					if( ans < brd[ XR ][ YR ] - brd[ XL ][ YR ] - brd[ XR ][ YL ] + brd[ XL ][ YL ] )
						ans = brd[ XR ][ YR ] - brd[ XL ][ YR ] - brd[ XR ][ YL ] + brd[ XL ][ YL ], I = i, J = j;
			printf( "%d (%d,%d)\n", ans, I, J );
		}
	}
}
