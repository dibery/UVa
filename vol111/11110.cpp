#include<cstdio>
#include<sstream>
using namespace std;
#define N 105

int fill( int grid[][ N ], int i, int j, int num )
{
	int ans = 1;

	grid[ i ][ j ] = 0;
	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( i != m ^ j != n && grid[ m ][ n ] == num )
				ans += fill( grid, m, n, num );

	return ans;
}

int main()
{
	for( int size, x, y; scanf( "%d%*c", &size ) == 1 && size; )
	{
		char s[ 10000 ] = { 0 };
		int grid[ N ][ N ] = { { 0 } };
		bool vis[ N ] = { true }, ok = true;

		for( int i = 1; i < size; ++i )
		{
			stringstream ss( gets( s ) );
			while( ss >> x >> y )
				grid[ x ][ y ] = i;
		}
		for( int i = 1; i <= size; ++i )
			for( int j = 1; j <= size; ++j )
				if( !grid[ i ][ j ] )
					grid[ i ][ j ] = size;

		for( int i = 1; i <= size && ok; ++i )
			for( int j = 1, n; j <= size && ok; ++j )
				if( !vis[ n = grid[ i ][ j ] ] && n )
				{
					vis[ grid[ i ][ j ] ] = true;
					ok &= fill( grid, i, j, n ) == size;
				}
				else if( vis[ n ] && n )
					ok = false;
		puts( ok? "good" : "wrong" );
	}
}
