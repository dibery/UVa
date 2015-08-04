#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, size, x, y, z;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int M[ 4 ] = { 0 }, m[ 4 ] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX }, D[ 4 ] = { 0 };

		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d %d", &x, &y, &z );
			M[ 0 ] = max( M[ 0 ], x+y+z );
			m[ 0 ] = min( m[ 0 ], x+y+z );
			M[ 1 ] = max( M[ 1 ], x-y+z );
			m[ 1 ] = min( m[ 1 ], x-y+z );
			M[ 2 ] = max( M[ 2 ], x+y-z );
			m[ 2 ] = min( m[ 2 ], x+y-z );
			M[ 3 ] = max( M[ 3 ], x-y-z );
			m[ 3 ] = min( m[ 3 ], x-y-z );
		}
		for( int i = 0; i < 4; ++i )
			D[ i ] = M[ i ] - m[ i ];
		printf( "Case #%d: %d\n", n, *max_element( D, D+4 ) );
	}
}
