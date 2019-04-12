#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
char brd[ 55 ][ 55 ];

int main()
{
	int t, h, w;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int move = INT_MAX;
		bool fail = false;

		scanf( "%d %d\n", &h, &w );
		for( int i = 0; i < h; ++i )
			fail |= !strchr( gets( brd[ i ] ), '0' );
		if( !fail )
			for( int i = 0; i < w; ++i )
			{
				int tmp = 0;
				for( int j = 0, k, l; j < h; ++j )
				{
					int L = INT_MAX, R = INT_MAX;
					for( k = i; k < w && brd[ j ][ k ] == '1'; ++k );
					if( k < w )
						R = k - i;
					for( l = i; l >= 0 && brd[ j ][ l ] == '1'; --l );
					if( l >= 0 )
						L = i - l;
					tmp += min( L, R );
				}
				move = min( tmp, move );
			}
		printf( "Case %d: %d\n", n, fail? -1 : move );
	}
}
