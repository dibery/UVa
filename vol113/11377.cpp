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
	int sssp( int s, int t, int d_offset = 0 )
	{
		typedef pair<int,int> pii;
		priority_queue<pii,vector<pii>,greater<pii>> dij;
		int dist[ size ];

		if( s == t )
			return 0;
		memset( dist, -1, sizeof( int ) * size );
		for( dij.emplace( d_offset, s ); !dij.empty(); )
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
	int T, vertex, edge, airport, query;

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d %d", &vertex, &edge, &airport ); ++t, puts( "" ) )
	{
		bool has_airport[ 2000 ] = { false };
		graph g( vertex );

		for( int a; airport-- && scanf( "%d", &a ); )
			has_airport[ --a ] = true;
		for( int u, v; edge-- && scanf( "%d %d", &u, &v ); )
		{
			--u, --v;
			g.add( u, v, !has_airport[ v ] );
			g.add( v, u, !has_airport[ u ] );
		}
		printf( "Case %d:\n", t );
		scanf( "%d", &query );
		for( int s, t; query-- && scanf( "%d %d", &s, &t ); )
			--s, --t, printf( "%d\n", g.sssp( s, t, !has_airport[ s ] ) );
	}
}
