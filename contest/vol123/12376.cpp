#include<cstdio>
#include<list>
using namespace std;

int main()
{
	int t, vertex, edge, score[ 100 ];

	scanf( "%d", &t );
	for( int N = 1; N <= t; ++N )
	{
		list<int> adj[ 100 ];
		int learn = 0, p;

		scanf( "%d %d", &vertex, &edge );
		for( int i = 0; i < vertex; ++i )
			scanf( "%d", score + i );
		for( int i = 0, e, b; i < edge; ++i )
			scanf( "%d %d", &b, &e ), adj[ b ].push_back( e );

		for( p = 0; !adj[ p ].empty(); )
		{
			list<int>::iterator next, i;
			int now = 0;
			for( i = adj[ p ].begin(); i != adj[ p ].end(); ++i )
				if( now < score[ *i ] )
					now = score[ *i ], next = i;
			p = *next;
			learn += now;
		}
		printf( "Case %d: %d %d\n", N, learn, p );
	}
}
