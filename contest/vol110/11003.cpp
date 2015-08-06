#include<bits/stdc++.h>
using namespace std;

int dp[ 1001 ][ 3001 ], w[ 1000 ], l[ 1000 ], size;

int main()
{
	for( int h = 1; scanf( "%d", &size ) && size; h = 1 )
	{
		memset( dp, 0, sizeof( dp ) );
		for( int i = 0; i < size; ++i )
			scanf( "%d %d", w + i, l + i );
		fill( dp[ size - 1 ] + w[ size - 1 ], dp[ size ], 1 );
		for( int i = size - 2; i >= 0; --i )
			for( int j = 0; j <= 3000; ++j )
				if( j >= w[ i ] )
					dp[ i ][ j ] = max( dp[ i+1 ][ j ], 1 + dp[ i+1 ][ min( j - w[ i ], l[ i ] ) ] );
				else
					dp[ i ][ j ] = dp[ i + 1 ][ j ];
		for( int i = 0; i < size-1; ++i )
			h = max( h, 1 + dp[ i + 1 ][ l[ i ] ] );
		printf( "%d\n", h );
	}
}
