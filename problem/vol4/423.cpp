#include<bits/stdc++.h>
#define W first
#define V second
using namespace std;
typedef pair<int,int> pii;

int main()
{
	for( int size; scanf( "%d", &size ) == 1; )
	{
		int adj[ 100 ][ 100 ] = { { 0 } }, dist[ 100 ] = { 0 };
		char n[ 9 ];
		priority_queue<pii,vector<pii>,greater<pii> > sssp;

		for( int i = 1; i < size; ++i )
			for( int j = 0; j < i; ++j )
			{
				scanf( "%s", n );
				if( *n != 'X' )
					adj[ j ][ i ] = adj[ i ][ j ] = atoi( n );
			}
		fill( dist + 1, dist + size, INT_MAX );
		for( int i = 1; i < size; ++i )
			if( adj[ 0 ][ i ] )
				sssp.push( make_pair( dist[ i ] = adj[ 0 ][ i ], i ) );
		while( !sssp.empty() )
			if( dist[ sssp.top().V ] < sssp.top().W )
				sssp.pop();
			else
			{
				int v = sssp.top().V, w = sssp.top().W;
				sssp.pop();
				for( int i = 1; i < size; ++i )
					if( w + adj[ v ][ i ] < dist[ i ] && adj[ v ][ i ] )
					{
						dist[ i ] = w + adj[ v ][ i ];
						sssp.push( make_pair( dist[ i ], i ) );
					}
			}
		printf( "%d\n", *max_element( dist, dist + size ) );
	}
}
