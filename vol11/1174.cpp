#include<bits/stdc++.h>
using namespace std;

template<typename edge=int>
struct graph
{
	graph( int SIZE ) { adj = new map<int,edge>[ size = SIZE ]; }
	void add( int u, int v, edge d = 1, bool bi = false )
	{
		adj[ u ][ v ] = d;
		if( bi )
			adj[ v ][ u ] = d;
	}
	edge mst( int start = 0 )
	{
		typedef pair<edge,int> node;
		typedef pair<int,edge> link;
		priority_queue<node,vector<node>,greater<node>> _mst;
		edge cost = 0;
		vector<bool> vis( size );

		for( const link& i: adj[ start ] )
			_mst.emplace( i.second, i.first );
		vis[ start ] = true;
		for( int found = 1; found < size && !_mst.empty(); )
		{
			node t = _mst.top();
			_mst.pop();
			if( vis[ t.second ] )
				continue;
			vis[ t.second ] = true;
			++found;
			cost += t.first;
			for( const link& i: adj[ t.second ] )
				if( !vis[ i.first ] )
					_mst.emplace( i.second, i.first );
		}

		return cost;
	}
	map<int, edge>* adj;
	int size;
};

int main()
{
	bool first = true;

	scanf( "%*d" );
	for( int v, e; scanf( "%d %d", &v, &e ) == 2; )
	{
		if( first )
			first = false;
		else
			puts( "" );

		graph<> g( v );
		map<string,int> id;
		int S, T, c;

		for( char s[ 9 ], t[ 9 ]; e-- && scanf( "%s %s %d", s, t, &c ); )
		{
			if( id.find( s ) == id.end() )
				id[ s ] = id.size();
			if( id.find( t ) == id.end() )
				id[ t ] = id.size();
			S = id[ s ];
			T = id[ t ];
			g.add( S, T, c, true );
		}
		printf( "%d\n", g.mst() );
	}
}
