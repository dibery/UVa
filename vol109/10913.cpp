#include<bits/stdc++.h>
using namespace std;

int ans[ 75 ][ 75 ][ 6 ][ 3 ]; // x, y, k, way (0=both,1=only left,2=only right)
bool vis[ 75 ][ 75 ][ 6 ][ 3 ];

int main()
{
	for( int dim, neg, brd[ 75 ][ 75 ], t = 0; scanf( "%d %d", &dim, &neg ) && dim; )
	{
		for( int i = 0; i < dim; ++i )
			for( int j = 0; j < dim; ++j )
				scanf( "%d", brd[ i ] + j );
		fill( ans[ 0 ][ 0 ][ 0 ], ans[ dim ][ 0 ][ 0 ], INT_MIN );
		memset( vis, false, sizeof( vis ) );
		ans[ 0 ][ 0 ][ **brd < 0 ][ 0 ] = **brd;
		vis[ 0 ][ 0 ][ **brd < 0 ][ 0 ] = true;
		for( int i = 1; i < dim; ++i )
			for( int j = 0; j <= neg; ++j )
				if( j + int( brd[ 0 ][ i ] < 0 ) <= neg )
				{
					int offset = brd[ 0 ][ i ] < 0, m = INT_MIN;
					for( int w = 0; w < 2; ++w )
						if( vis[ 0 ][ i - 1 ][ j ][ w ] )
							m = max( m, ans[ 0 ][ i - 1 ][ j ][ w ] );
					if( m == INT_MIN )
						continue;
					ans[ 0 ][ i ][ j + offset ][ 1 ] = m + brd[ 0 ][ i ];
					vis[ 0 ][ i ][ j + offset ][ 1 ] = true;
				}
		for( int i = 1; i < dim; ++i )
		{
			for( int j = 0; j < dim; ++j )
			{
				int offset = brd[ i ][ j ] < 0;
				for( int k = 0; k + offset <= neg; ++k )
				{
					int m = INT_MIN;
					for( int w = 0; w < 3; ++w )
						if( vis[ i - 1 ][ j ][ k ][ w ] )
							m = max( m, ans[ i - 1 ][ j ][ k ][ w ] );
					if( m == INT_MIN )
						continue;
					vis[ i ][ j ][ k + offset ][ 0 ] = true;
					ans[ i ][ j ][ k + offset ][ 0 ] = m + brd[ i ][ j ];
				}
			}
			for( int j = 1; j < dim; ++j )
			{
				int offset = brd[ i ][ j ] < 0;
				for( int k = 0; k + offset <= neg; ++k )
				{
					int m = INT_MIN;
					for( int w = 0; w < 3; ++w )
						if( w != 2 && vis[ i ][ j - 1 ][ k ][ w ] )
							m = max( m, ans[ i ][ j - 1 ][ k ][ w ] );
					if( m == INT_MIN )
						continue;
					vis[ i ][ j ][ k + offset ][ 1 ] = true;
					ans[ i ][ j ][ k + offset ][ 1 ] = m + brd[ i ][ j ];
				}
			}
			for( int j = dim - 2; j >= 0; --j )
			{
				int offset = brd[ i ][ j ] < 0;
				for( int k = 0; k + offset <= neg; ++k )
				{
					int m = INT_MIN;
					for( int w = 0; w < 3; ++w )
						if( w != 1 && vis[ i ][ j + 1 ][ k ][ w ] )
							m = max( m, ans[ i ][ j + 1 ][ k ][ w ] );
					if( m == INT_MIN )
						continue;
					vis[ i ][ j ][ k + offset ][ 2 ] = true;
					ans[ i ][ j ][ k + offset ][ 2 ] = m + brd[ i ][ j ];
				}
			}
		}
		printf( "Case %d: ", ++t );
		if( find( *vis[ dim - 1 ][ dim - 1 ], *vis[ dim - 1 ][ dim ], true ) != *vis[ dim - 1 ][ dim ] )
			printf( "%d\n", *max_element( *ans[ dim - 1 ][ dim - 1 ], *ans[ dim - 1 ][ dim ] ) );
		else
			puts( "impossible" );
	}
}
