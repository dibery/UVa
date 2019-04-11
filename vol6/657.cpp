#include<cstdio>
#include<cstring>
#include<list>
using namespace std;
char field[ 55 ][ 55 ];
bool vis[ 55 ][ 55 ];
int h, w, point, t = 0;
list<int>all;
list<int>::iterator it;
void elim( int i, int j, bool clear = false )
{
	if( !i || !j || i > h || j > w )
		return;
	if( clear )
		field[ i ][ j ] = '*';
	vis[ i ][ j ] = true;
	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( m == i ^ n == j && !vis[ m ][ n ] && field[ m ][ n ] == 'X' )
				elim( m, n, true );
}
void dfs( int i, int j )
{
	if( !i || !j || i > h || j > w )
		return;
	vis[ i ][ j ] = true;
	point += field[ i ][ j ] == 'X';
	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( m == i ^ n == j && !vis[ m ][ n ] && field[ m ][ n ] != '.' )
				dfs( m, n );
}

int main()
{
	while( scanf( "%d %d\n", &w, &h ) && w+h )
	{
		memset( vis, false, sizeof( vis ) );
		memset( field, 0, sizeof( field ) );
		all.clear();
		for( int i = 1; i <= h; ++i )
			gets( field[ i ]+1 );
		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( field[ i ][ j ] == 'X' && !vis[ i ][ j ] )
					elim( i, j );
//		for( int i = 1; i <= h; ++i )
//			puts( field[ i ]+1 );
		memset( vis, false, sizeof( vis ) );
		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( ( field[ i ][ j ] == '*' || field[ i ][ j ] == 'X' ) && !vis[ i ][ j ] )
				{
					point = 0;
					dfs( i, j );
					if( point )
						all.push_back( point );
				}
		all.sort();
		printf( "Throw %d\n", ++t );
		for( it = all.begin(); it != all.end(); ++it )
			printf( "%s%d", it == all.begin()? "" : " ", *it );
		puts( "\n" );
	}

	return 0;
}
