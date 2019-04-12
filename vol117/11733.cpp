#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T, V, E, airport;

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d %d", &V, &E, &airport ); ++t )
	{
		auto *adj = new list<pair<int,int>>[ V + 1 ];

		for( int i = 1; i <= V; ++i )
			adj[ 0 ].emplace_back( i, airport ), adj[ i ].emplace_back( 0, airport );
		for( int u, v, cost; E-- && scanf( "%d %d %d", &u, &v, &cost ); )
			if( cost < airport )
				adj[ u ].emplace_back( v, cost ), adj[ v ].emplace_back( u, cost );

		int cost = 0, built = 0;
		bool vis[ 10001 ] = { true };
		typedef pair<int,int> node;
		priority_queue<node,vector<node>,greater<node>> mst;

		for( int i = 1; i <= V; ++i )
			mst.emplace( airport, i );
		for( int found = 0; found < V; )
		{
			auto t = mst.top();
			mst.pop();
			if( vis[ t.second ] )
				continue;
			vis[ t.second ] = true;
			++found;
			cost += t.first;
			built += t.first == airport;
			for( auto i: adj[ t.second ] )
				if( !vis[ i.first ] )
					mst.emplace( i.second, i.first );
		}
		printf( "Case #%d: %d %d\n", t, cost, built );
		delete[] adj;
	}
}
