#include<cstdio>
#include<cstdlib>
#include<list>
#include<algorithm>
using namespace std;

list<int> adj[ 5000 ];
int dist[ 5000 ];
bool vis[ 5000 ];

void DFS( int& farthest, int now = 0, int parent = 0, int depth = 0, int* deepest = (int*)calloc( 0, sizeof( int ) ) )
{
	dist[ now ] = max( dist[ now ], depth );
	vis[ now ] = true;
	if( depth > *deepest )
		*deepest = depth, farthest = now;
	for( list<int>::iterator i = adj[ now ].begin(); i != adj[ now ].end(); ++i )
		if( !vis[ *i ] )
			DFS( farthest, *i, now, depth+1, deepest );
	if( !depth )
		free( deepest );
}

int main()
{
	int all, endA, endB, no_use;

	while( scanf( "%d", &all ) == 1 )
	{
		for( int i = 0, j, s; i < all; ++i )
			for( adj[ i ].clear(), scanf( "%d", &s ); s--; )
				scanf( "%d", &j ), adj[ i ].push_back( j-1 );

		DFS( endA );
		fill( dist, dist+all, 0 );
		fill( vis, vis+all, false );
		DFS( endB, endA );
		fill( vis, vis+all, false );
		DFS( no_use, endB );

		int far = *max_element( dist, dist+all ), near = *min_element( dist, dist+all );
		
		printf( "Best Roots  :" );
		for( int i = 0; i < all; ++i )
			if( dist[ i ] == near )
				printf( " %d", i+1 );
		printf( "\nWorst Roots :" );
		for( int i = 0; i < all; ++i )
			if( dist[ i ] == far )
				printf( " %d", i+1 );
		puts( "" );
		fill( dist, dist+all, 0 );
		fill( vis, vis+all, false );
	}
}
