#include<cstdio>

void fill( char brd[ 5 ][ 5 ], int occupy[ 5 ][ 5 ], int size, int i, int j, int c )
{
	for( int x = j; x < size && brd[ i ][ x ] == '.'; ++x )
		occupy[ i ][ x ] += c;
	for( int x = j; x >= 0 && brd[ i ][ x ] == '.'; --x )
		occupy[ i ][ x ] += c;
	for( int x = i; x < size && brd[ x ][ j ] == '.'; ++x )
		occupy[ x ][ j ] += c;
	for( int x = i; x >= 0 && brd[ x ][ j ] == '.'; --x )
		occupy[ x ][ j ] += c;
}

void dfs( char brd[ 5 ][ 5 ], int occupy[ 5 ][ 5 ], int size, int& ans, int m, int n, int put )
{
	for( int i = m; i < size; ++i )
		for( int j = ( i == m? n : 0 ); j < size; ++j )
			if( !occupy[ i ][ j ] && brd[ i ][ j ] == '.' )
			{
				fill( brd, occupy, size, i, j, 1 );
				dfs( brd, occupy, size, ans, i, j, put + 1 );
				fill( brd, occupy, size, i, j, -1 );
			}
	ans = ans < put? put : ans;
}

int main()
{
	int size;
	char brd[ 5 ][ 5 ];

	while( scanf( "%d", &size ) && size )
	{
		int ans = 0;
		int occupy[ 5 ][ 5 ] = { { 0 } };
		for( int i = 0; i < size; ++i )
			scanf( "%s", brd[ i ] );
		dfs( brd, occupy, size, ans, 0, 0, 0 );
		printf( "%d\n", ans );
	}
}
