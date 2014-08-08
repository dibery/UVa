#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, size, id;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		int solve[ 3 ][ 10001 ] = { 0 }, uniq[ 3 ] = { 0 }, big = 0;
		
		for( int i = 0; i < 3; ++i )
			for( scanf( "%d", &size ); size--; )
				scanf( "%d", &id ), solve[ i ][ id ] = 1;
		for( int i = 0; i < 3; ++i )
			for( int j = 0; j <= 10000; ++j )
				if( solve[ 0 ][ j ] + solve[ 1 ][ j ] + solve[ 2 ][ j ] == 1 && solve[ i ][ j ] )
					++uniq[ i ];
		for( int i = 0; i < 3; ++i )
			big = max( big, uniq[ i ] );

		printf( "Case #%d:\n", n );
		for( int i = 0; i < 3; ++i )
			if( uniq[ i ] == big )
			{
				printf( "%d %d", i+1, big );
				for( int j = 0; j <= 10000; ++j )
					if( solve[ 0 ][ j ] + solve[ 1 ][ j ] + solve[ 2 ][ j ] == 1 && solve[ i ][ j ] )
						printf( " %d", j );
				puts( "" );
			}
	}
}
