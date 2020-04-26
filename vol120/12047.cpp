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
		adj[ u ][ v ] = d;
	}
	vector<int> sssp( int s )
	{
		typedef pair<int,int> pii;
		priority_queue<pii,vector<pii>,greater<pii>> dij;
		int dist[ size ];

		memset( dist, -1, sizeof( int ) * size );
		for( dij.emplace( 0, s ); !dij.empty(); )
		{
			int d = dij.top().first, pos = dij.top().second;
			dij.pop();
			if( ~dist[ pos ] )
				continue;
			dist[ pos ] = d;
			for( auto& p: adj[ pos ] )
				if( !~dist[ p.first ] )
					dij.emplace( d + p.second, p.first );
		}
		return vector<int>( dist, dist + size );
	}
	map<int, int>* adj;
	int size;
};

int main()
{
	int T, node, edge, s, t, poll;

	for( scanf( "%d", &T ); T-- && scanf( "%d %d %d %d %d", &node, &edge, &s, &t, &poll ); )
	{
		graph g( node ), g2( node );
		map<pair<int,int>,int> edges;
		int ans = -1;

		for( int x, y, d; edge-- && scanf( "%d %d %d", &x, &y, &d ); )
			--x, --y, g.add( x, y, d ), g2.add( y, x, d ), edges[ make_pair( x, y ) ] = d;

		auto S = g.sssp( --s ), T = g2.sssp( --t );
		for( auto& e: edges )
			if( e.second + S[ e.first.first ] + T[ e.first.second ] <= poll && ~S[ e.first.first ] && ~T[ e.first.second ] )
				ans = max( ans, e.second );
		printf( "%d\n", ans );
	}
}
