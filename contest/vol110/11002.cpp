#include<bits/stdc++.h>
using namespace std;
bool exist[ 59 ][ 30 ][ 6001 ];

int main()
{
	for( int size, n[ 59 ][ 30 ]; scanf( "%d", &size ) && size; memset( exist, 0, sizeof( exist ) ) )
	{
		int ans = INT_MAX;

		for( int i = 0; i < 2*size; ++i )
			for( int j = 0; j < size - abs( i - size ); ++j )
				scanf( "%d", n[ i-1 ] + j );

		exist[ 0 ][ 0 ][ **n + 3000 ] = true;
		for( int i = 1; i < size; ++i )
			for( int j = 0; j <= i; ++j )
				for( int k = 0; k <= 6000; ++k )
				{
					if( exist[ i-1 ][ j ][ k ] )
						exist[ i ][ j ][ k + n[ i ][ j ] ] = exist[ i ][ j ][ k - n[ i ][ j ] ] = true;
					if( j && exist[ i-1 ][ j-1 ][ k ] )
						exist[ i ][ j ][ k + n[ i ][ j ] ] = exist[ i ][ j ][ k - n[ i ][ j ] ] = true;
				}
		for( int i = size; i < 2*size-1; ++i )
			for( int j = 0; j < size - ( i - size + 1 ); ++j )
				for( int k = 0; k <= 6000; ++k )
				{
					if( exist[ i-1 ][ j ][ k ] )
						exist[ i ][ j ][ k + n[ i ][ j ] ] = exist[ i ][ j ][ k - n[ i ][ j ] ] = true;
					if( exist[ i-1 ][ j+1 ][ k ] )
						exist[ i ][ j ][ k + n[ i ][ j ] ] = exist[ i ][ j ][ k - n[ i ][ j ] ] = true;
				}
		for( int i = 0; i <= 6000; ++i )
			if( exist[ 2*size-2 ][ 0 ][ i ] )
				ans = min( ans, abs( i-3000 ) );
		printf( "%d\n", ans );
	}
}
