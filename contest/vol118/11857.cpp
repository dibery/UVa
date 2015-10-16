#include<cstdio>
#include<climits>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
#define list vector
using namespace std;
typedef pair<int,int> pii;
const int N = 1000001;

int main()
{
	for( int V, E; scanf( "%d %d", &V, &E ) && V; )
	{
		int dist[ N ] = { 0 }, ans;
		list<pii> *adj = new list<pii>[ N ];
		priority_queue<pii,vector<pii>,greater<pii> > mst;

		for( int a, b, w; E-- && scanf( "%d %d %d", &a, &b, &w ); )
			adj[ a ].push_back( pii( w, b ) ), adj[ b ].push_back( pii( w, a ) );

		fill( dist + 1, dist + V, INT_MAX );
		for( pii& i: *adj )
			mst.push( i );
		while( !mst.empty() )
			if( dist[ mst.top().second ] != INT_MAX )
				mst.pop();
			else
			{
				int v = mst.top().second, w = mst.top().first;

				mst.pop();
				dist[ v ] = w;
				for( pii& i: adj[ v ] )
					if( dist[ i.second ] == INT_MAX )
						mst.push( i );
			}

		ans = *max_element( dist, dist + V );
		if( ans == INT_MAX )
			puts( "IMPOSSIBLE" );
		else
			printf( "%d\n", ans );
		delete[] adj;
	}
}
