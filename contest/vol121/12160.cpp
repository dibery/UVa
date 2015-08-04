#include<cstdio>
#include<list>
#include<queue>
#define NEXT (bfs.front()+add[i])%10000
using namespace std;

int main()
{
	int lock, unlock, item, add[ 10 ], t = 0;

	while( scanf( "%d %d %d", &lock, &unlock, &item ) && lock+unlock+item )
	{
		int d[ 10000 ] = { 0 };
		queue<int> bfs;
		for( int i = 0; i < item; ++i )
			scanf( "%d", add+i );
		d[ lock ] = 1;
		for( bfs.push( lock ); !d[ unlock ] && !bfs.empty(); bfs.pop() )
			for( int i = 0; i < item; ++i )
				if( !d[ NEXT ] )
					d[ NEXT ] = d[ bfs.front() ] + 1, bfs.push( NEXT );
		if( d[ unlock ] )
			printf( "Case %d: %d\n", ++t, d[ unlock ] - 1 );
		else
			printf( "Case %d: Permanently Locked\n", ++t );
	}
}
