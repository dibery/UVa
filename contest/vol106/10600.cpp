#include<bits/stdc++.h>
using namespace std;

int mst_cost( multimap<int,int> adj[], int v, list<pair<int,int>> *edges, int a = -1, int b = -1 )
{
	typedef tuple<int,int,int> node;
	priority_queue<node,vector<node>,greater<node>> mst;
	bool vis[ 100 ] = { true }, skipped = false;
	int cost = 0;

	if( a > b )
		swap( a, b );
	for( auto& i: *adj )
		mst.emplace( i.second, 0, i.first );
	while( !mst.empty() )
	{
		auto t = mst.top();
		mst.pop();
		//printf( "See (%d, %d) %d\n", get<1>(t), get<2>(t), get<0>(t) );
		if( !skipped && min( get<1>( t ), get<2>( t ) ) == a && max( get<1>( t ), get<2>( t ) ) == b )
		{
			skipped = true;
			continue;
		}
		if( vis[ get<2>( t ) ] )
			continue;
		//printf( "Use edge (%d, %d)\n", get<1>(t)+1, get<2>(t)+1 );
		vis[ get<2>( t ) ] = true;
		cost += get<0>( t );
		--v;
		if( edges )
			edges->emplace_back( get<1>( t ), get<2>( t ) );
		for( auto& i: adj[ get<2>( t ) ] )
			if( !vis[ i.first ] )
				mst.emplace( i.second, get<2>( t ), i.first );
	}
	//printf( "Cost = %d\n", cost );
	//puts( "###" );
	return v > 1? INT_MAX : cost;
}

int main()
{
	int t, v, e;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &v, &e ); )
	{
		multimap<int,int> adj[ 100 ];
		list<pair<int,int>> mst_edge;

		for( int a, b, c; e-- && scanf( "%d %d %d", &a, &b, &c ); )
			adj[ --a ].emplace( --b, c ), adj[ b ].emplace( a, c );

		int cost = mst_cost( adj, v, &mst_edge ), second_cost = INT_MAX;
		//continue;
		for( auto& i: mst_edge )
		{
			//printf( "Remove edge (%d, %d)\n", i.first, i.second );
			second_cost = min( second_cost, mst_cost( adj, v, NULL, i.first, i.second ) );
		}
		printf( "%d %d\n", cost, second_cost );
	}
}
