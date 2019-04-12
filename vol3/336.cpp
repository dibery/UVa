#include<cstdio>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	for( int edge, t = 0; scanf( "%d", &edge ) && edge; )
	{
		map<int,vector<int> > adj;

		for( int b, e; edge-- && scanf( "%d %d", &b, &e ); )
			adj[ b ].push_back( e ), adj[ e ].push_back( b );

		for( int start, ttl; scanf( "%d %d", &start, &ttl ) && ( start || ttl ); )
		{
			map<int,int> dist;
			queue<int> bfs;
			if( ttl && adj.find( start ) != adj.end() )
				bfs.push( start );
			if( adj.find( start ) != adj.end() )
				dist[ start ] = 0;
			for( ; !bfs.empty(); bfs.pop() )
				for( int i = 0; i < adj[ bfs.front() ].size(); ++i )
					if( dist.find( adj[ bfs.front() ][ i ] ) == dist.end() )
					{
						dist[ adj[ bfs.front() ][ i ] ] = dist[ bfs.front() ] + 1;
						if( dist[ adj[ bfs.front() ][ i ] ] < ttl )
							bfs.push( adj[ bfs.front() ][ i ] );
					}
			printf( "Case %d: %lu nodes not reachable from node %d with TTL = %d.\n", ++t, adj.size() - dist.size(), start, ttl );
		}
	}
}
