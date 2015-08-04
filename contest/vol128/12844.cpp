#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, w[ 10 ], a, b, c, d, e, o[ 5 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		for( int i = 0; i < 10; ++i )
			scanf( "%d", w+i );
		do
		{
			if( ( w[ 1 ] - w[ 0 ] + w[ 4 ] ) % 2 )
				continue;
			c = ( w[ 1 ] - w[ 0 ] + w[ 4 ] ) / 2.0;
			a = w[ 1 ] - c;
			b = w[ 0 ] - a;
			d = w[ 2 ] - a;
			e = w[ 3 ] - a;
			if( b+d == w[ 5 ] && b+e == w[ 6 ] && c+d == w[ 7 ] && c+e == w[ 8 ] && d+e == w[ 9 ] )
				break;
		} while( next_permutation( w+2, w+8 ) );

		o[ 0 ] = a, o[ 1 ] = b, o[ 2 ] = c, o[ 3 ] = d, o[ 4 ] = e;
		sort( o, o+5 );
		printf( "Case %d: %d %d %d %d %d\n", n, o[ 0 ], o[ 1 ], o[ 2 ], o[ 3 ], o[ 4 ] );
	}
}
