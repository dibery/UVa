#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main()
{
	int t, begin, end, vertex, edge, w;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d %d", &vertex, &edge, &begin, &end );
		list<pii> adj[ vertex ];
		priority_queue<pii,vector<pii>,greater<pii> > proc;
		int dist[ 20000 ] = { 0 };

		for( int i = 0, b, e; i < edge; ++i )
		{
			scanf( "%d %d %d", &b, &e, &w );
			adj[ b ].push_back( make_pair( e, w ) );
			adj[ e ].push_back( make_pair( b, w ) );
		}

		fill( dist, dist+vertex, INT_MAX );
		for( proc.push( make_pair( 0, begin ) ); !proc.empty() && proc.top().second != end; )
			if( proc.top().first > dist[ proc.top().second ] )
				proc.pop();
			else
			{
				int V = proc.top().second, D = proc.top().first;

				proc.pop();
				dist[ V ] = D;
				for( list<pii>::iterator i = adj[ V ].begin(); i != adj[ V ].end(); ++i )
					if( D + i->second < dist[ i->first ] )
						proc.push( make_pair( dist[ i->first ] = D + i->second, i->first ) );
			}

		if( dist[ end ] == INT_MAX )
			printf( "Case #%d: unreachable\n", n );
		else
			printf( "Case #%d: %d\n", n, dist[ end ] );
	}
}
