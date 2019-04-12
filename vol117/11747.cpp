#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main()
{
	for( int v, e; scanf( "%d %d", &v, &e ) && v; )
	{
		bool vis[ 1000 ] = { false };
		map<int,int> G[ 1000 ];
		set<int> ws;

		for( int bg, ed, w; e-- && scanf( "%d %d %d", &bg, &ed, &w ); )
			ws.insert( G[ bg ][ ed ] = G[ ed ][ bg ] = w );
		for( int P = 0; P < v; ++P )
			if( !vis[ P ] && !G[ P ].empty() )
			{
				priority_queue<pii,vector<pii>,greater<pii> > mst;
				vis[ P ] = true;
				for( auto& i: G[ P ] )
					mst.push( make_pair( i.second, i.first ) );
				while( !mst.empty() )
					if( vis[ mst.top().second ] )
						mst.pop();
					else
					{
						int p = mst.top().second;
						ws.erase( mst.top().first );
						vis[ p ] = true;
						mst.pop();
						for( auto& i: G[ p ] )
							if( !vis[ i.first ] )
								mst.push( make_pair( i.second, i.first ) );
					}
			}
		if( ws.empty() )
			puts( "forest" );
		else
			for( auto i = ws.begin(); i != ws.end(); ++i )
				printf( "%d%c", *i, next( i ) == ws.end()? '\n' : ' ' );
	}
}
