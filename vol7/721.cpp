#include<bits/stdc++.h>
#define V second
#define D first
#define N 1000000
using namespace std;
typedef pair<int,int> pii;

int dijk( list<pii>* adj, int vertex )
{
	int dist[ N ] = { 0 };
	bool vis[ N ] = { false };
	priority_queue< pii, vector<pii>, greater<pii> > proc;

	proc.push( make_pair( 0, 0 ) );
	fill( dist+1, dist+vertex, INT_MAX );
	
	while( !proc.empty() )
		if( vis[ proc.top().V ] )
			proc.pop();
		else
		{
			pii now = proc.top();
			proc.pop();
			++vis[ now.V ];
			dist[ now.V ] = now.D;

			for( list<pii>::iterator i = adj[ now.V ].begin(); i != adj[ now.V ].end(); ++i )
				if( !vis[ i->V ] && dist[ now.V ] + i->D < dist[ i->V ] )
					dist[ i->V ] = dist[ now.V ] + i->D, proc.push( make_pair( dist[ i->V ], i->V ) );
		}

	return accumulate( dist, dist + vertex, 0 );
}

int main()
{
	int vertex, edge, t;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &vertex, &edge );
		list<pii> *adj = new list<pii>[ vertex ], *inv = new list<pii>[ vertex ];

		for( int a, b, c; edge && scanf( "%d %d %d", &a, &b, &c ); --edge )
			adj[ a-1 ].push_back( make_pair( c, b-1 ) ), inv[ b-1 ].push_back( make_pair( c, a-1 ) );

		printf( "%d\n", dijk( adj, vertex ) + dijk( inv, vertex ) );
		delete[] adj, delete[] inv;
	}
}
