#include<bits/stdc++.h>
#define s bfs.front()
using namespace std;

struct state
{
	int x, y, dir, color;
	state( int X = 0, int Y = 0, int C = 0, int D = 0 ) { x = X; y = Y; dir = D; color = C; }
	bool operator == ( state& c ) { return x == c.x && y == c.y && color == c.color; }
} stop;

int main()
{
	int h, w, t = 0, dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
	char brd[ 30 ][ 30 ];
	bool first = true;

	while( scanf( "%d %d%*c", &h, &w ) && h+w )
	{
		bool vis[ 30 ][ 30 ][ 5 ][ 4 ] = { { { { 0 } } } };
		int dist[ 30 ][ 30 ][ 5 ][ 4 ] = { { { { 0 } } } };
		queue<state> bfs;

		memset( brd, '#', sizeof( brd ) );
		for( int i = 1; i <= h; ++i )
			gets( brd[ i ] + 1 ), brd[ i ][ w+1 ] = '#';

		fill( dist[ 0 ][ 0 ][ 0 ], dist[ 30 ][ 0 ][ 0 ], INT_MAX );
		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( brd[ i ][ j ] == 'S' )
					bfs.push( state( i, j ) ), **vis[ i ][ j ] = true, **dist[ i ][ j ] = 1;
				else if( brd[ i ][ j ] == 'T' )
					stop = state( i, j );

		for( ; !bfs.empty() && !( bfs.front() == stop ); bfs.pop() )
		{
			if( !vis[ s.x + dx[ s.dir ] ][ s.y + dy[ s.dir ] ][ ( s.color + 1 ) % 5 ][ s.dir ] && brd[ s.x + dx[ s.dir ] ][ s.y + dy[ s.dir ] ] != '#' )
			{
				vis[ s.x + dx[ s.dir ] ][ s.y + dy[ s.dir ] ][ ( s.color + 1 ) % 5 ][ s.dir ] = true;
				dist[ s.x + dx[ s.dir ] ][ s.y + dy[ s.dir ] ][ ( s.color + 1 ) % 5 ][ s.dir ] = dist[ s.x ][ s.y ][ s.color ][ s.dir ] + 1;
				bfs.push( state( s.x + dx[ s.dir ], s.y + dy[ s.dir ], ( s.color + 1 ) % 5, s.dir ) );
			}
			if( !vis[ s.x ][ s.y ][ s.color ][ ( s.dir + 3 ) % 4 ] )
			{
				vis[ s.x ][ s.y ][ s.color ][ ( s.dir + 3 ) % 4 ] = true;
				dist[ s.x ][ s.y ][ s.color ][ ( s.dir + 3 ) % 4 ] = dist[ s.x ][ s.y ][ s.color ][ s.dir ] + 1;
				bfs.push( state( s.x, s.y, s.color, ( s.dir + 3 ) % 4 ) );
			}
			if( !vis[ s.x ][ s.y ][ s.color ][ ( s.dir + 1 ) % 4 ] )
			{
				vis[ s.x ][ s.y ][ s.color ][ ( s.dir + 1 ) % 4 ] = true;
				dist[ s.x ][ s.y ][ s.color ][ ( s.dir + 1 ) % 4 ] = dist[ s.x ][ s.y ][ s.color ][ s.dir ] + 1;
				bfs.push( state( s.x, s.y, s.color, ( s.dir + 1 ) % 4 ) );
			}
		}

		if( first )
			first = false;
		else
			puts( "" );
		if( bfs.empty() )
			printf( "Case #%d\ndestination not reachable\n", ++t );
		else
			printf( "Case #%d\nminimum time = %d sec\n", ++t, dist[ s.x ][ s.y ][ s.color ][ s.dir ] - 1 );
	}
}
