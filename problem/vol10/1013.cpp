#include<bits/stdc++.h>
using namespace std;
typedef pair< double, pair<int,int> > LNK;

void dfs( double adj[ 50 ][ 50 ], double dist[], int size, int pos = 0, double D = 0 )
{
	dist[ pos ] = D;
	for( int i = 1; i < size; ++i )
		if( dist[ i ] == -1 && adj[ pos ][ i ] != -1 )
			dfs( adj, dist, size, i, max( D, adj[ pos ][ i ] ) );
}

int main()
{
	for( int size, t = 1; scanf( "%d", &size ) && size; ++t )
	{
		int x[ 50 ], y[ 50 ], live[ 50 ];
		double adj[ 50 ][ 50 ], dist[ 50 ] = { 0 }, D = 0, M = 0, MST[ 50 ][ 50 ];
		bool vis[ 50 ] = { false };
		priority_queue< LNK, vector<LNK>, greater<LNK> > tmp;

		for( int i = 0; i < size; ++i )
			scanf( "%d %d %d", x+i, y+i, live+i );
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				adj[ i ][ j ] = hypot( x[ i ] - x[ j ], y[ i ] - y[ j ] );
		fill( &MST[ 0 ][ 0 ], &MST[ 50 ][ 0 ], -1 );
		fill( dist, dist+50, -1 );

		*vis = true;
		for( int i = 1; i < size; ++i )
			tmp.push( LNK( adj[ 0 ][ i ], pair<int,int>( 0, i ) ) );
		while( !tmp.empty() )
		{
			int next = tmp.top().second.second, now = tmp.top().second.first;
			double D = tmp.top().first;
			tmp.pop();

			if( vis[ next ] )
				continue;
			vis[ next ] = true;
			MST[ now ][ next ] = MST[ next ][ now ] = D;
			for( int i = 0; i < size; ++i )
				if( !vis[ i ] )
					tmp.push( LNK( adj[ next ][ i ], pair<int,int>( next, i ) ) );
		}

		dfs( MST, dist, size );
		for( int i = 0; i < size; ++i )
			D += dist[ i ] * live[ i ], M += live[ i ];
		printf( "Island Group: %d Average %.2f\n\n", t, D/M );
	}
}

