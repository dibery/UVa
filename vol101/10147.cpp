#include<bits/stdc++.h>
using namespace std;

double dist[ 750 ][ 750 ];

void dfs( int pos, bool vis[], vector<int> adj[], vector<int>& connect )
{
	vis[ pos ] = true;
	connect.push_back( pos );
	for( int i: adj[ pos ] )
		if( !vis[ i ] )
			dfs( i, vis, adj, connect );
}

int main()
{
	int T, city, x[ 750 ], y[ 750 ], road;
	bool first = true;

	for( scanf( "%d", &T ); T-- && scanf( "%d", &city ); )
	{
		if( first )
			first = false;
		else
			puts( "" );
		for( int i = 0; i < city; ++i )
			scanf( "%d %d", x + i, y + i );
		for( int i = 0; i < city; ++i )
			for( int j = 0; j < city; ++j )
				dist[ i ][ j ] = dist[ j ][ i ] = hypot( x[ i ] - x[ j ], y[ i ] - y[ j ] );

		vector<int> adj[ 750 ];
		bool vis[ 750 ] = { false }, build = false;

		scanf( "%d", &road );
		for( int s, t; road-- && scanf( "%d %d", &s, &t ); )
			--s, --t, adj[ s ].push_back( t ), adj[ t ].push_back( s );
		for( int i = 0; i < city; ++i )
		{
			vector<int> connect;
			if( !vis[ i ] )
				dfs( i, vis, adj, connect );
			for( int s: connect )
				for( int t: connect )
					dist[ s ][ t ] = dist[ t ][ s ] = 0;
		}

		memset( vis, false, sizeof( vis ) );
		priority_queue<pair<double,pair<int,int>>> mst;

		for( mst.emplace( 0, make_pair( 0, 0 ) ); !mst.empty(); )
		{
			auto top = mst.top().second;
			int s = top.first, t = top.second;
			mst.pop();
			if( vis[ t ] )
				continue;
			vis[ t ] = true;
			for( int i = 0; i < city; ++i )
				if( !vis[ i ] )
					mst.emplace( -dist[ t ][ i ], make_pair( t, i ) );
			if( dist[ s ][ t ] )
				build = true, printf( "%d %d\n", ++s, ++t );
		}
		if( !build )
			puts( "No new highways need" );
	}
}
