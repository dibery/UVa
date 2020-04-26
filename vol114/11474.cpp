#include<bits/stdc++.h>
using namespace std;

struct node
{
	vector<pair<int,int>> pos;
	int dist;

	node( int d, int len = 1 ) : dist( d * d )
	{
		for( int i = 0, x, y; i < len; ++i )
			scanf( "%d %d", &x, &y ), pos.emplace_back( x, y );
	}
	bool reach( node& rhs )
	{
		for( auto& i: pos )
			for( auto& j: rhs.pos )
				if( pow( i.first - j.first, 2 ) + pow( i.second - j.second, 2 ) <= rhs.dist )
					return true;
		return false;
	}
};

void dfs( vector<node>& plane, int len, int idx, bool vis[] )
{
	vis[ idx ] = true;
	for( int i = 0; i < len; ++i )
		if( !vis[ i ] && plane[ idx ].reach( plane[ i ] ) )
			dfs( plane, len, i, vis );
}

int main()
{
	int t, tree, doctor, d_tree, d_doctor;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d %d %d", &tree, &doctor, &d_tree, &d_doctor ); )
	{
		vector<node> plane;
		bool vis[ 110 ] = { false };

		for( int i = 0; i < doctor; ++i )
			plane.emplace_back( d_doctor );
		for( int i = 0, n; i < tree && scanf( "%d", &n ); ++i )
			plane.emplace_back( d_tree, n );

		dfs( plane, tree + doctor, doctor, vis );
		puts( find( vis, vis + doctor, true ) == vis + doctor? "Tree can't be saved :(" : "Tree can be saved :)" );
	}
}
