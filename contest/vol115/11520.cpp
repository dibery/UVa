#include<cstdio>
#include<cstring>
bool get;

bool ok( char grid[ 10 ][ 10 ], int size )
{
	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			for( int m = i-1; m <= i+1; ++m )
				for( int n = j-1; n <= j+1; ++n )
					if( i == m ^ n == j && m >= 0 && m < size && n >= 0 && n < size )
						if( grid[ i ][ j ] == grid[ m ][ n ] && grid[ i ][ j ] != '.' )
							return false;
	return true;
}

void solve( char grid[ 10 ][ 10 ], int size, int i = 0, int j = 0 )
{
	if( i == size )
	{
		for( int i = 0; i < size; ++i, puts( "" ) )
			for( int j = 0; j < size; ++j )
				putchar( grid[ i ][ j ] );
		get = true;
		return;
	}
	if( grid[ i ][ j ] != '.' )
	{
		if( ok( grid, size ) )
			solve( grid, size, i + ( j == size-1 ), j == size-1? 0 : j+1 );
		return;
	}
	for( char c = 'A'; c <= 'Z'; ++c )
	{
		grid[ i ][ j ] = c;
		if( ok( grid, size ) )
			solve( grid, size, i + ( j == size-1 ), j == size-1? 0 : j+1 );
		if( !get )
			grid[ i ][ j ] = '.';
		else
			return;
	}
}

int main()
{
	int t, size;
	char grid[ 10 ][ 10 ], tmp[ 11 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d\n", &size );
		for( int i = 0; i < size; ++i )
			gets( tmp ), strncpy( grid[ i ], tmp, size );
		get = false;
		printf( "Case %d:\n", n );
		solve( grid, size );
	}
}
