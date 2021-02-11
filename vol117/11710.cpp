#include<bits/stdc++.h>
using namespace std;

struct graph
{
	graph( int SIZE ) { adj = new map<int,int>[ size = SIZE ]; }
	void add( int u, int v, int d, bool bi = true )
	{
		adj[ u ][ v ] = d;
		if( bi )
			adj[ v ][ u ] = d;
	}
	int mst( int start = 0 )
	{
		if( !connected() )
			return -1;
		typedef pair<int,int> node;
		typedef node link;
		priority_queue<node,vector<node>,greater<node>> _mst;
		int cost = 0;
		vector<bool> vis( size );

		for( const link& i: adj[ start ] )
			_mst.emplace( i.second, i.first );
		vis[ start ] = true;
		for( int found = 1; found < size; )
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
	bool connected()
	{
		vector<bool> vis( size );
		queue<int> bfs;

		for( bfs.push( 0 ), vis[ 0 ] = true; !bfs.empty(); bfs.pop() )
			for( const pair<int,int>& i: adj[ bfs.front() ] )
				if( !vis[ i.first ] )
					vis[ i.first ] = true, bfs.push( i.first );
		return all_of( vis.begin(), vis.end(), []( bool i ) { return i; } );
	}
	map<int, int>* adj;
	int size;
};

int main()
{
	for( int v, e, c; scanf( "%d %d", &v, &e ) && v; )
	{
		map<string,int> id;
		graph g( v );

		for( char s[ 30 ]; v-- && scanf( "%s", s ); )
			id[ s ] = v;
		for( char s[ 30 ], t[ 30 ]; e-- && scanf( "%s %s %d", s, t, &c ); )
			g.add( id[ s ], id[ t ], c, true );
		scanf( "%*s" );
		if( ( c = g.mst() ) != -1 )
			printf( "%d\n", c );
		else
			puts( "Impossible" );
	}
}
