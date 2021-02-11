#include<bits/stdc++.h>
using namespace std;

struct graph
{
	graph( int SIZE ) { adj = new map<int,double>[ size = SIZE ]; }
	void add( int u, int v, double d = 1, bool bi = false )
	{
		adj[ u ][ v ] = d;
		if( bi )
			adj[ v ][ u ] = d;
	}
	vector<double> mst( int start = 0 )
	{
		typedef pair<double,int> node;
		typedef pair<int,double> link;
		priority_queue<node,vector<node>,greater<node>> _mst;
		vector<double> cost;
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
			cost.push_back( t.first );
			for( const link& i: adj[ t.second ] )
				if( !vis[ i.first ] )
					_mst.emplace( i.second, i.first );
		}

		return cost;
	}
	map<int, double>* adj;
	int size;
};

int main()
{
	int T, v, dist, x[ 1000 ], y[ 1000 ];

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d", &v, &dist ); ++t )
	{
		graph g( v );
		while( v-- )
			scanf( "%d %d", x + v, y + v );
		for( int i = 0; i < g.size; ++i )
			for( int j = i + 1; j < g.size; ++j )
				g.add( i, j, hypot( x[ i ] - x[ j ], y[ i ] - y[ j ] ), true );
		int state = 1;
		double road = 0, rail = 0;
		for( double i: g.mst() )
			if( i > dist )
				rail += i, ++state;
			else
				road += i;
		printf( "Case #%d: %d %.0f %.0f\n", t, state, road, rail );
	}
}
