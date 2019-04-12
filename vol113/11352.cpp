#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> pii;

int main()
{
	int t, h, w, dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 }, dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	char brd[ 101 ][ 101 ] = { { 0 } };

	for( scanf( "%d", &t ); t--; )
	{
		queue<pii> bfs;
		int dist[ 101 ][ 101 ] = { { 0 } };

		scanf( "%d %d", &h, &w );
		for( int i = 0; i < h; ++i )
			scanf( "%s", brd[ i ] );

		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				if( brd[ i ][ j ] == 'A' )
					bfs.push( pii( i, j ) );
				else if( brd[ i ][ j ] == 'Z' )
					for( int k = 0; k < 8; ++k )
						if( i + dx[ k ] < h && i + dx[ k ] >= 0 && j + dy[ k ] < w &&
								j + dy[ k ] >= 0 && brd[ i + dx[ k ] ][ j + dy[ k ] ] == '.' )
							brd[ i + dx[ k ] ][ j + dy[ k ] ] = 'X';

		for( ; !bfs.empty() && brd[ bfs.front().first ][ bfs.front().second ] != 'B'; bfs.pop() )
			for( int i = bfs.front().first - 1; i <= bfs.front().first + 1; ++i )
				for( int j = bfs.front().second - 1; j <= bfs.front().second + 1; ++j )
					if( ( i != bfs.front().first || j != bfs.front().second ) && i < h && i >= 0 &&
							j < w && j >= 0 && ( brd[ i ][ j ] == '.' || brd[ i ][ j ] == 'B' ) && !dist[ i ][ j ] )
					{
						dist[ i ][ j ] = dist[ bfs.front().first ][ bfs.front().second ] + 1;
						bfs.push( pii( i, j ) );
					}

		if( bfs.empty() )
			puts( "King Peter, you can't go now!" );
		else
			printf( "Minimal possible length of a trip is %d\n", dist[ bfs.front().first ][ bfs.front().second ] );
	}
}
