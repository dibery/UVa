#include<bits/stdc++.h>
using namespace std;

bool adj[ 750 ][ 750 ];
double grp_adj[ 750 ][ 750 ];

void dfs( int idx, int grp[], int gid, int size )
{
	grp[ idx ] = gid;
	for( int i = 0; i < size; ++i )
		if( !~grp[ i ] && adj[ idx ][ i ] )
			dfs( i, grp, gid, size );
}

int main()
{
	for( int building, cable, x[ 750 ], y[ 750 ]; scanf( "%d", &building ) == 1; )
	{
		for( int i = 0; i < building; ++i )
			scanf( "%d %d", x + i, y + i );
		scanf( "%d", &cable );
		memset( adj, false, sizeof( adj ) );
		for( int u, v; cable-- && scanf( "%d %d", &u, &v ); )
			--u, --v, adj[ u ][ v ] = adj[ v ][ u ] = true;

		int grp[ 750 ], groups;
		set<int> group_content[ 750 ];
		memset( grp, -1, sizeof( grp ) );
		
		for( int i = 0, id = 0; i < building; ++i )
			if( !~grp[ i ] )
				dfs( i, grp, groups = id++, building );
		for( int i = 0; i < building; ++i )
			group_content[ grp[ i ] ].insert( i );
		
		fill( grp_adj[ 0 ], grp_adj[ groups ], INT_MAX );
		for( int i = 0; i <= groups; ++i )
			for( int j = i + 1; j <= groups; ++j )
				for( auto& m: group_content[ i ] )
					for( auto& n: group_content[ j ] )
						grp_adj[ i ][ j ] = grp_adj[ j ][ i ] = min( grp_adj[ i ][ j ], hypot( x[ m ] - x[ n ], y[ m ] - y[ n ] ) );

		typedef pair<double,int> node;
		priority_queue<node,vector<node>,greater<node>> mst;
		double cost = 0;
		bool vis[ 750 ] = { false };

		for( mst.emplace( 0, 0 ); !mst.empty(); )
		{
			auto top = mst.top();
			mst.pop();
			if( vis[ top.second ] )
				continue;
			vis[ top.second ] = true;
			cost += top.first;
			for( int i = 0; i <= groups; ++i )
				if( !vis[ i ] )
					mst.emplace( grp_adj[ top.second ][ i ], i );
		}
		printf( "%.2f\n", cost );
	}
}
