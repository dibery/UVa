#include<bits/stdc++.h>
using namespace std;

struct node
{
	int d, h, w;
	node( int D, int H = 0, int W = 0 ) : d( D ), h( H ), w( W ) {}
	bool operator> ( const node& n ) const { return d > n.d; }
};

inline bool ok( int a, int b, int c ) { return a >= b && a < c; }

const int dh[] = { 1, 0, -1, 0 }, dw[] = { 0, 1, 0, -1 };
int t, h, w, cost[ 1000 ][ 1000 ], dist[ 1000 ][ 1000 ];

int main()
{
	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &h, &w ); )
	{
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
			{
				scanf( "%d", cost[ i ] + j );
				dist[ i ][ j ] = INT_MAX;
			}

		priority_queue<node,vector<node>,greater<node>> sssp;

		for( sssp.push( node( **cost ) ); !sssp.empty() && dist[ h - 1 ][ w - 1 ] == INT_MAX; )
			if( dist[ sssp.top().h ][ sssp.top().w ] != INT_MAX )
				sssp.pop();
			else
			{
				auto n = sssp.top();

				sssp.pop();
				dist[ n.h ][ n.w ] = n.d;
#define NH n.h + dh[ i ]
#define NW n.w + dw[ i ]
				for( int i = 0; i < 4; ++i )
					if( ok( NH, 0, h ) && ok( NW, 0, w ) && dist[ NH ][ NW ] == INT_MAX )
						sssp.push( node( n.d + cost[ NH ][ NW ], NH, NW ) );
			}

		printf( "%d\n", dist[ h - 1 ][ w - 1 ] );
	}
}
