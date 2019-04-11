#include<bits/stdc++.h>
using namespace std;
const int N = 10000;

int main()
{
	for( int f, t; scanf( "%d %d", &f, &t ) == 2; )
	{
		int dist[ N ];
		queue<int> bfs;

		memset( dist, -1, sizeof( dist ) );
		dist[ f ] = 0;
		
		for( bfs.push( f ); !~dist[ t ]; bfs.pop() )
		{
			int n = bfs.front(), next[] = { n + 1, n * 2, n / 3 };
			for( int i: next )
				if( !~dist[ i % N ] )
					dist[ i % N ] = dist[ n ] + 1, bfs.push( i % N );
		}
		printf( "%d\n", dist[ t ] );
	}
}
