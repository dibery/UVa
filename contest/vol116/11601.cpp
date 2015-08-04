#include<cstdio>
#include<algorithm>
using namespace std;

char overlap( char brd[ 200 ][ 200 ], int lx, int ly, int rx, int ry )
{
	for( int i = lx; i < rx; ++i )
		for( int j = ly; j < ry; ++j )
			if( brd[ i ][ j ] )
				return true;
	return false;
}

int main()
{
	int t, n = 1, lx, ly, rx, ry, size;

	for( scanf( "%d", &t ); n <= t; ++n )
	{
		int ans = 0;
		char brd[ 200 ][ 200 ] = { { 0 } };
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d %d %d", &lx, &ly, &rx, &ry );
			lx += 99, ly += 99, rx += 99, ry += 99;
			if( !overlap( brd, lx, ly, rx, ry ) )
				for( int i = lx; i < rx; ++i )
					for( int j = ly; j < ry; ++j )
						if( !brd[ i ][ j ] )
							brd[ i ][ j ] = 1, ++ans;
		}
		printf( "Case %d: %d\n", n, ans );
	}
}
