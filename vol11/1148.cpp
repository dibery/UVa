#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T, people, from, to, dist[ 100000 ];
	list<int> *adj = new list<int>[ 100000 ];
	
	for( scanf( "%d", &T ); T-- && scanf( "%d", &people ); )
	{
		for( int i = 0, id, fid, know; i < people; ++i )
			for( scanf( "%d %d", &id, &know ); know-- && scanf( "%d", &fid ); )
				adj[ id ].push_back( fid );
		scanf( "%d %d", &from, &to );
		memset( dist, 0, sizeof( dist ) );
		queue<int> bfs;
		for( bfs.push( from ); !bfs.empty() && !dist[ to ]; bfs.pop() )
			for( int i: adj[ bfs.front() ] )
				if( !dist[ i ] && i != from )
					dist[ i ] = dist[ bfs.front() ] + 1, bfs.push( i );
		printf( "%d %d %d\n%s", from, to, dist[ to ] - 1, T? "\n" : "" );
		for( int i = 0; i < people; ++i )
			adj[ i ].clear();
	}
}
