#include<cstdio>
#include<cstring>
void dfs( char maze[ 32 ][ 82 ], int i, int j )
{
	maze[ i ][ j ] = '#';
	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( m == i ^ n == j && maze[ m ][ n ] == ' ' )
				dfs( maze, m, n );
}

int main()
{
	int t;
	for( scanf( "%d\n", &t ); t--; puts( "_____" ) )
	{
		int n = 0, x, y;
		char maze[ 32 ][ 82 ] = { 0 };
		while( gets( maze[ ++n ]+1 ) && maze[ n ][ 1 ] != '_' );
		for( x = 1; x < n; ++x )
			if( strchr( maze[ x ]+1, '*' ) )
			{
				y = strchr( maze[ x ]+1, '*' ) - maze[ x ];
				break;
			}
		dfs( maze, x, y );
		for( int i = 1; i < n; ++i )
			puts( maze[ i ]+1 );
	}

	return 0;
}
