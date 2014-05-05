#include<cstdio>
#include<algorithm>
class node
{
	public:
	int time;
	char type;
	node() { time = 0; }
};
bool cmp( const node& a, const node& b ) { return a.time != b.time? a.time > b.time : a.type < b.type; }
void dfs( char** map, int i, int j, bool** visit )
{
	visit[ i ][ j ] = true;
	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( !visit[ m ][ n ] && m == i ^ n == j && map[ m ][ n ] == map[ i ][ j ] )
				dfs( map, m, n, visit );
}

int main()
{
	int t, h, w;
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d %d", &h, &w );
		char** map = new char*[ h+2 ];
		bool** visit = new bool*[ h+2 ];
		for( int j = 0; j < h+2; ++j )
			map[ j ] = new char[ w+2 ], visit[ j ] = new bool[ w ];
		for( int m = 0; m <= h+1; ++m )
			for( int n = 0; n <= w+1; ++n )
				map[ m ][ n ] = 0;
		for( int m = 0; m < h; ++m )
			for( int n = 0; n < w; ++n )
				visit[ m ][ n ] = false;
		for( int j = 1; j <= h; ++j )
			scanf( "%s", map[ j ]+1 );
		node stat[ 26 ];
		for( int j = 0; j < 26; ++j )
			stat[ j ].type = 'a'+j;
		for( int m = 1; m <= h; ++m )
			for( int n = 1; n <= w; ++n )
				if( !visit[ m ][ n ] )
				{
					++stat[ map[ m ][ n ] - 'a' ].time;
					dfs( map, m , n, visit );
				}
		std::sort( stat, stat+26, cmp );
		printf( "World #%d\n", i );
		for( int j = 0; j < 26; ++j )
			if( stat[ j ].time )
				printf( "%c: %d\n", stat[ j ].type, stat[ j ].time );
	}

	return 0;
}
