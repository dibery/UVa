#include<bits/stdc++.h>
#define V second
#define D first
#define N 1000
using namespace std;
typedef pair<int,int> pii;

int main()
{
	for( int vertex, edge, t = 1; scanf( "%d %d", &vertex, &edge ) == 2; ++t )
	{
		list<pii> adj[ N ];
		bool vis[ N ] = { false };
		int dist[ N ] = { 0 };
		priority_queue< pii, vector<pii>, greater<pii> > proc;

		for( int a, b, c; edge && scanf( "%d %d %d", &a, &b, &c ); --edge )
		{
			adj[ a ].push_back( make_pair( c, b+vertex ) );
			adj[ b ].push_back( make_pair( c, a+vertex ) );
			adj[ a+vertex ].push_back( make_pair( c, b ) );
			adj[ b+vertex ].push_back( make_pair( c, a ) );
		}
		proc.push( make_pair( 0, 0 ) );
		fill( dist+1, dist+N, INT_MAX );

		while( !proc.empty() && !vis[ vertex - 1 ] )
			if( vis[ proc.top().second ] )
				proc.pop();
			else
			{
				pii now = proc.top();
				proc.pop();
				++vis[ now.V ];
				dist[ now.V ] = now.D;

				for( list<pii>::iterator i = adj[ now.V ].begin(); i != adj[ now.V ].end(); ++i )
					if( !vis[ i->V ] && dist[ now.V ] + i->D <= dist[ i->V ] )
					{
						dist[ i->V ] = dist[ now.V ] + i->D;
						proc.push( make_pair( dist[ i->V ], i->V ) );
					}
			}
		printf( dist[ vertex - 1 ] == INT_MAX? "Set #%d\n?\n" : "Set #%d\n%d\n", t, dist[ vertex - 1 ] );
	}
}
