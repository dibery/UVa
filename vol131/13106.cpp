#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	for( int r, c; scanf( "%d %d", &r, &c ) == 2; )
	{
		int brd[ 300 ][ 300 ], col[ 300 ], sum[ 300 ];

		for( int i = 0; i < r; ++i )
			for( int j = 0; j < c; ++j )
				scanf( "%d", brd[ i ] + j );
		for( int i = 0; i < c; ++i )
		{
			int val[ 300 ] = { brd[ 0 ][ i ], max( brd[ 0 ][ i ], brd[ 1 ][ i ] ) };
			for( int j = 2; j < r; ++j )
				val[ j ] = max( val[ j - 1 ], val[ j - 2 ] + brd[ j ][ i ] );
			col[ i ] = val[ r - 1 ];
		}
		sum[ 0 ] = col[ 0 ];
		sum[ 1 ] = max( col[ 0 ], col[ 1 ] );
		for( int i = 2; i < c; ++i )
			sum[ i ] = max( sum[ i - 1 ], sum[ i - 2 ] + col[ i ] );
		printf( "%d\n", sum[ c - 1 ] );
	}
}
