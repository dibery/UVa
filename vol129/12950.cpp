#include<bits/stdc++.h>
using namespace std;

struct graph
{
	graph( int SIZE )
	{
		adj = new map<int,int>[ size = SIZE ];
	}
	void add( int u, int v, int d )
	{
		adj[ u ][ v ] = adj[ v ][ u ] = d;
	}
	int sssp( int s, int t )
	{
		typedef pair<int,int> pii;
		priority_queue<pii,vector<pii>,greater<pii>> dij;
		int dist[ size ];

		memset( dist, -1, sizeof( int ) * size );
		for( dij.emplace( 0, s ); !dij.empty(); )
		{
			int d = dij.top().first, pos = dij.top().second;
			if( pos == t )
				return d;
			dij.pop();
			if( ~dist[ pos ] )
				continue;
			dist[ pos ] = d;
			for( auto& p: adj[ pos ] )
				if( !~dist[ p.first ] )
					dij.emplace( d + p.second, p.first );
		}
		return -1;
	}
	map<int, int>* adj;
	int size;
};

int main()
{
	for( int node, edge; scanf( "%d %d", &node, &edge ) == 2; )
	{
		graph g( node * 2 );
		for( int u, v, d; edge-- && scanf( "%d %d %d", &u, &v, &d ); )
		{
			--u, --v;
			g.add( u * 2, v * 2 + 1, d );
			g.add( u * 2 + 1, v * 2, d );
		}
		printf( "%d\n", g.sssp( 0, node * 2 - 2 ) );
	}
}
