#include<bits/stdc++.h>
#define V second
#define D first
using namespace std;
typedef pair<int,int> pii;

void dfs( set<int>* src, int p, bool* show )
{
	if( show[ p ] )
		return;
	++show[ p ];
	for( set<int>::iterator i = src[ p ].begin(); i != src[ p ].end(); ++i )
		if( !show[ *i ] )
			dfs( src, *i, show );
}

int main()
{
	for( int vertex, edge; scanf( "%d %d", &vertex, &edge ) == 2; )
	{
		list<pii> adj[ 10000 ];
		set<int> src[ 10000 ];
		bool vis[ 10000 ] = { false }, exist[ 10000 ] = { false };
		int dist[ 10000 ] = { 0 }, ans = 0;
		priority_queue< pii, vector<pii>, greater<pii> > dijkstra;

		for( int a, b, c; edge && scanf( "%d %d %d", &a, &b, &c ); --edge )
			adj[ a ].push_back( make_pair( c, b ) ), adj[ b ].push_back( make_pair( c, a ) );
		dijkstra.push( make_pair( 0, 0 ) );
		fill( dist+1, dist+10000, INT_MAX );

		while( !dijkstra.empty() && !vis[ vertex-1 ] )
			if( vis[ dijkstra.top().second ] )
				dijkstra.pop();
			else
			{
				pii now = dijkstra.top();
				dijkstra.pop();
				++vis[ now.V ];
				dist[ now.V ] = now.D;

				for( list<pii>::iterator i = adj[ now.V ].begin(); i != adj[ now.V ].end(); ++i )
					if( !vis[ i->V ] && dist[ now.V ] + i->D <= dist[ i->V ] )
					{
						if( dist[ now.V ] + i->D < dist[ i->V ] )
							src[ i->V ].clear();
						src[ i->V ].insert( now.V );
						dist[ i->V ] = dist[ now.V ] + i->D;
						dijkstra.push( make_pair( dist[ i->V ], i->V ) );
					}
			}
		dfs( src, vertex-1, exist );
		for( int i = 0; i < vertex-1; ++i )
			if( exist[ i ] )
				for( list<pii>::iterator j = adj[ i ].begin(); j != adj[ i ].end(); ++j )
					if( exist[ j->V ] && dist[ j->V ] - dist[ i ] == j->D && src[ j->V ].find( i ) != src[ j->V ].end() )
						ans += j->D;
		printf( "%d\n", ans*2 );
	}
}
