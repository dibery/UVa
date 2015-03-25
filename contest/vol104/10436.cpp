#include<bits/stdc++.h>
#define V second
#define D first
using namespace std;
typedef pair<int,int> pii;

void path( int* src, string* name, int stop, int now )
{
	if( src[ now ] != -1 )
		path( src, name, stop, src[ now ] );
	printf( "%s%c", name[ now ].c_str(), now == stop? '\n' : ' ' );
}

int main()
{
	int t, v, e, q, w, seat;
	string name[ 20 ], a, b;
	cin >> t;

	for( int n = 1; n <= t; ++n )
	{
		map<string,int> id, pass;
		int edge[ 20 ][ 20 ] = { { 0 } };

		cin >> v;
		for( int i = 0; i < v; ++i )
			cin >> name[ i ] >> w, id[ name[ i ] ] = i, pass[ name[ i ] ] = w;

		cin >> e;
		for( int i = 0; i < e; ++i )
		{
			cin >> a >> b >> w;
			edge[ id[ a ] ][ id[ b ] ] = 2*w + pass[ b ];
			edge[ id[ b ] ][ id[ a ] ] = 2*w + pass[ a ];
		}

		printf( "Map #%d\n", n );
		cin >> q;
		for( int m = 1; m <= q; ++m )
		{
			cin >> a >> b >> seat;
			int src[ v ], dist[ v ];
			bool vis[ 20 ] = { false };
			priority_queue< pii, vector<pii>, greater<pii> > proc;

			fill( src, src+v, -1 );
			fill( dist, dist+v, INT_MAX );
			proc.push( make_pair( dist[ id[ a ] ] = pass[ a ], id[ a ] ) );

			while( !proc.empty() && !vis[ id[ b ] ] )
				if( vis[ proc.top().V ] )
					proc.pop();
				else
				{
					pii now = proc.top();
					proc.pop();
					++vis[ now.V ];
					for( int i = 0; i < v; ++i )
						if( edge[ now.V ][ i ] && !vis[ i ] && now.D + edge[ now.V ][ i ] < dist[ i ] )
							proc.push( make_pair( dist[ i ] = now.D + edge[ now.V ][ i ], i ) ), src[ i ] = now.V;
				}

			printf( "Query #%d\n", m );
			path( src, name, id[ b ], id[ b ] );
			printf( "Each passenger has to pay : %.2f taka\n", 1.1 * dist[ id[ b ] ] / seat );
		}
		if( n < t )
			puts( "" );
	}
}
