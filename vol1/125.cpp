#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int t = 0, E; scanf( "%d", &E ) == 1; )
	{
		int path[ 30 ][ 30 ] = { { 0 } }, V = -1;

		for( int x, y; E-- && scanf( "%d %d", &x, &y ); )
			path[ x ][ y ] = 1, V = max( V, max( x, y ) );

		for( int m = 0; m <= V; ++m )
			for( int b = 0; b <= V; ++b )
				for( int e = 0; e <= V; ++e )
					path[ b ][ e ] += path[ b ][ m ] * path[ m ][ e ];
		for( int m = 0; m <= V; ++m )
			if( path[ m ][ m ] )
				for( int b = 0; b <= V; ++b )
					for( int e = 0; e <= V; ++e )
						if( path[ b ][ m ] && path[ m ][ e ] )
							path[ b ][ e ] = -1;

		printf( "matrix for city %d\n", t++ );
		for( int i = 0; i <= V; ++i )
			for( int j = 0; j <= V; ++j )
				printf( "%d%c", path[ i ][ j ], j == V? '\n' : ' ' );
	}
}
