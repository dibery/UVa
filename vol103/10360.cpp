#include<bits/stdc++.h>
using namespace std;

int brd[ 1025 ][ 1025 ], t, d, n;

int main()
{
	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &d, &n ); )
	{
		for( int x, y, q; n-- && scanf( "%d %d %d", &x, &y, &q ); )
			for( int i = max( 0, x - d ); i <= min( 1024, x + d ); ++i )
				for( int j = max( 0, y - d ); j <= min( 1024, y + d ); ++j )
					brd[ i ][ j ] += q;
		int *pos = max_element( brd[ 0 ], brd[ 1025 ] );
		printf( "%lld %lld %d\n", ( pos - *brd ) / 1025, ( pos - *brd ) % 1025, *pos );
		memset( brd, 0, sizeof( brd ) );
	}
}
