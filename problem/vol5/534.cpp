#include<bits/stdc++.h>
using namespace std;
typedef pair<double, pair<int,int> > node;

int main()
{
	for( int t = 0, stone; scanf( "%d", &stone ) && stone; )
	{
		int x[ 200 ], y[ 200 ];
		double dist[ 200 ] = { 0 };
		priority_queue<node,vector<node>,greater<node> > mst;

		for( int i = 0; i < stone; ++i )
			scanf( "%d %d", x+i, y+i );
		for( int i = 1; i < stone; ++i )
			mst.push( make_pair( hypot( x[ 0 ] - x[ i ], y[ 0 ] - y[ i ] ), make_pair( 0, i ) ) );

		while( !dist[ 1 ] )
		{
			double D = mst.top().first;
			int from = mst.top().second.first, to = mst.top().second.second;

			mst.pop();
			dist[ to ] = max( D, dist[ from ] );
			for( int i = 1; i < stone; ++i )
				if( !dist[ i ] )
					mst.push( make_pair( hypot( x[ to ] - x[ i ], y[ to ] - y[ i ] ), make_pair( to, i ) ) );
		}

		printf( "Scenario #%d\nFrog Distance = %.3f\n\n", ++t, dist[ 1 ] );
	}
}
