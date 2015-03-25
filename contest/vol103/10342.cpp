#include<bits/stdc++.h>
#define V second
#define D first
#define N 200
using namespace std;
typedef pair<int,int> pii;

int main()
{
	for( int vertex, edge, query, from, to, t = 1; scanf( "%d %d", &vertex, &edge ) == 2; ++t )
	{
		list<pii> adj[ N ];

		for( int a, b, c; edge && scanf( "%d %d %d", &a, &b, &c ); --edge )
		{
			adj[ a ].push_back( make_pair( c, b ) );
			adj[ b ].push_back( make_pair( c, a ) );
		}

		for( scanf( "%d", &query ), printf( "Set #%d\n", t ); query--; )
		{
			int dist[ N ] = { 0 };
			bool vis[ N ] = { false };
			priority_queue< pii, vector<pii>, greater<pii> > proc;

			scanf( "%d %d", &from, &to );
			proc.push( make_pair( 0, from ) );
			fill( dist, dist+N, INT_MAX );
			dist[ from ] = 0;

			while( !proc.empty() && !vis[ to+vertex ] )
				if( vis[ proc.top().second ] )
					proc.pop();
				else
				{
					pii now = proc.top();
					proc.pop();
					++vis[ now.V ];
					dist[ now.V ] = now.D;

					for( list<pii>::iterator i = adj[ now.V % vertex ].begin(); i != adj[ now.V % vertex ].end(); ++i )
						if( !vis[ i->V ] && dist[ now.V ] + i->D < dist[ i->V ] && ( dist[ i->V ] != dist[ i->V + vertex ] || dist[ i->V ] == INT_MAX ) )
						{
							dist[ i->V + vertex ] = dist[ i->V ];
							dist[ i->V ] = dist[ now.V ] + i->D;
							proc.push( make_pair( dist[ i->V ], i->V ) );
							if( dist[ i->V + vertex ] != INT_MAX )
								proc.push( make_pair( dist[ i->V + vertex ], i->V + vertex ) );
						}
						else if( !vis[ i->V + vertex ] && dist[ now.V ] + i->D < dist[ i->V + vertex ] && dist[ now.V ] + i->D != dist[ i->V ] )
						{
							dist[ i->V + vertex ] = dist[ now.V ] + i->D;
							proc.push( make_pair( dist[ i->V + vertex ], i->V + vertex ) );
						}
				}
			printf( dist[ to+vertex ] == INT_MAX? "?\n" : "%d\n", dist[ to+vertex ] );
		}
	}
}
