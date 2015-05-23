#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main()
{
	for( int v, e, s, t, c; scanf( "%d %d", &v, &e ) && v; )
	{
		list<pii> adj[ v ];
		bool vis[ 200000 ] = { false };
		int cost = 0, all = 0;
		priority_queue<pii,vector<pii>,greater<pii> > mst;

		while( e-- )
		{
			scanf( "%d %d %d", &s, &t, &c );
			all += c;
			adj[ s ].push_back( make_pair( t, c ) );
			adj[ t ].push_back( make_pair( s, c ) );
		}

		for( mst.push( make_pair( 0, 0 ) ); !mst.empty(); )
			if( !vis[ mst.top().second ] )
			{
				int V = mst.top().second, D = mst.top().first;
				mst.pop();
				cost += D;
				vis[ V ] = true;
				for( list<pii>::iterator i = adj[ V ].begin(); i != adj[ V ].end(); ++i )
					if( !vis[ i->first ] )
						mst.push( make_pair( i->second, i->first ) );
			}
			else
				mst.pop();

		printf( "%d\n", all - cost );
	}
}
