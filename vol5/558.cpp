#include<cstdio>
#include<climits>
#include<map>
#include<algorithm>
using namespace std;

struct edge
{
	int begin, end, w;
	edge() { scanf( "%d %d %d", &begin, &end, &w ); }
} *adj;

int main()
{
	int t, v, e;

	for( scanf( "%d", &t ); t--; delete[] adj )
	{
		scanf( "%d %d", &v, &e );
		adj = new edge[ e ];
		int dist[ 1000 ] = { 0 };
		bool neg = false;

		fill( dist + 1, dist + v, INT_MAX );
		for( int i = 1; i < v; ++i )
			for( int j = 0; j < e; ++j )
				if( dist[ adj[ j ].begin ] != INT_MAX )
					dist[ adj[ j ].end ] = min( dist[ adj[ j ].end ], dist[ adj[ j ].begin ] + adj[ j ].w );
		for( int i = 0; i < e; ++i )
			if( dist[ adj[ i ].begin ] != INT_MAX )
				neg |= dist[ adj[ i ].begin ] + adj[ i ].w < dist[ adj[ i ].end ];
		puts( neg? "possible" : "not possible" );
	}
}
