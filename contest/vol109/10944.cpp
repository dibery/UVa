#include<bits/stdc++.h>
using namespace std;

const int PT = 15, M = 1 << PT;
int bit1[ M ] = { 0 }, order[ M ] = { 0 };
auto dist = [] ( pair<int,int> a, pair<int,int> b ) { return max( abs( a.first - b.first ), abs( a.second - b.second ) ); };

int main()
{
	for( int i = 1; i < M; ++i )
		bit1[ i ] = 1 + bit1[ i ^ i & -i ], order[ i ] = i;
	sort( order, order + M, [] ( int a, int b ) { return bit1[ a ] < bit1[ b ]; } );

	for( int h, w; ~scanf( "%d %d", &h, &w ); )
	{
		char brd[ 20 ], size = 0;
		pair<int,int> start, food[ PT ];
		int ans[ PT ][ M ], out = INT_MAX;

		for( int i = 0; i < h; ++i )
		{
			scanf( "%s", brd );
			for( int j = 0; j < w; ++j )
				if( brd[ j ] == 'L' )
					start = make_pair( i, j );
				else if( brd[ j ] == '#' )
					food[ size++ ] = make_pair( i, j );
		}

		fill( ans[ 0 ], ans[ PT ], INT_MAX );
		for( int i = 0; i < size; ++i )
			ans[ i ][ 0 ] = dist( food[ i ], start );
		for( int state: order )
			if( state < 1 << size && state )
				for( int i = 0; i < size; ++i )
					for( int j = 0; j < size; ++j )
						if( i != j && state & 1 << j )
							ans[ i ][ state ] = min( ans[ i ][ state ], dist( food[ i ], food[ j ] ) + ans[ j ][ state & ~( 1 << j ) ] );

		for( int i = 0; i < size; ++i )
			out = min( out, dist( start, food[ i ] ) + ans[ i ][ ( 1 << size ) - 1 ^ 1 << i ] );
		if( !size )
			out = 0;
		printf( "%d\n", out );
	}
}
