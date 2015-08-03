#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int emp, t, begin, adj[ 2500 ][ 15 ] = { { 0 } }, size[ 2500 ] = { 0 };

	scanf( "%d", &emp );
	for( int i = 0; i < emp; ++i )
	{
		scanf( "%d", size + i );
		for( int j = 0; j < size[ i ]; ++j )
			scanf( "%d", &adj[ i ][ j ] );
	}
	for( scanf( "%d", &t ); t--; )
	{
		queue<int> bfs;
		int dist[ 2500 ] = { 0 }, day[ 2500 ] = { 0 }, *M;

		scanf( "%d", &begin );
		for( bfs.push( begin ); !bfs.empty(); bfs.pop() )
			for( int i = 0; i < size[ bfs.front() ]; ++i )
				if( adj[ bfs.front() ][ i ] != begin && !dist[ adj[ bfs.front() ][ i ] ] )
				{
					bfs.push( adj[ bfs.front() ][ i ] );
					++day[ dist[ adj[ bfs.front() ][ i ] ] = dist[ bfs.front() ] + 1 ];
				}
		M = max_element( day, day + 2500 );
		if( size[ begin ] )
			printf( "%d %d\n", *M, M - day );
		else
			puts( "0" );
	}
}
