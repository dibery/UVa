#include<cstdio>
#include<list>
#include<queue>
using namespace std;

int main()
{
	int begin, end, t = 0, prime[ 1001 ] = { 2 }, size = 1;
	bool check[ 1001 ] = { false };
	list<int> adj[ 1001 ];

	for( int i = 3; i < 1000; i += 2 )
	{
		for( int j = 3; j*j <= i && !check[ i ]; j += 2 )
			if( i % j == 0 )
				check[ i ] = true;
		if( !check[ i ] )
			prime[ size++ ] = i;
	}
	for( int i = 3; i <= 1000; ++i )
		for( int j = 0; j < size && prime[ j ] < i; ++j )
			if( i % prime[ j ] == 0 )
				adj[ i ].push_back( i + prime[ j ] );

	while( scanf( "%d %d", &begin, &end ) && begin )
	{
		queue<int> bfs;
		int dist[ 1001 ] = { 0 };

		for( bfs.push( begin ); !bfs.empty() && !dist[ end ]; bfs.pop() )
			for( list<int>::iterator it = adj[ bfs.front() ].begin(); it != adj[ bfs.front() ].end() && *it <= end; ++it )
				if( !dist[ *it ] )
					dist[ *it ] = dist[ bfs.front() ] + 1, bfs.push( *it );
		printf( "Case %d: %d\n", ++t, dist[ end ] || end == begin? dist[ end ] : -1 );
	}
}
