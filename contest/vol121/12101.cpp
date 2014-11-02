#include<cstdio>
#include<cstdlib>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

bool isp( int n )
{
	for( int i = 3; i * i <= n; i += 2 )
		if( n % i == 0 )
			return false;
	return true;
}

int main()
{
	int t, from, to;
	bool isprime[ 10000 ] = { false };
	set<int> adj[ 10000 ];

	for( int i = 1001; i < 10000; i += 2 )
		isprime[ i ] = isp( i );
	for( int i = 1001; i < 10000; i += 2 )
	{
		char tmp[ 10 ];
		for( int n = 0; n < 4; ++n )
		{
			sprintf( tmp, "%d", i );
			for( int s = n? '0' : '1'; s <= '9'; ++s )
			{
				tmp[ n ] = s;
				if( atoi( tmp ) != i && isprime[ atoi( tmp ) ] )
					adj[ i ].insert( atoi( tmp ) );
			}
		}
	}

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &from, &to );
		queue<int> bfs;
		int dist[ 10000 ] = { 0 };

		for( bfs.push( from ); !bfs.empty() && dist[ to ] == 0 && from != to; bfs.pop() )
			for( set<int>::iterator i = adj[ bfs.front() ].begin(); i != adj[ bfs.front() ].end(); ++i )
				if( dist[ *i ] == 0 && *i != from )
					dist[ *i ] = dist[ bfs.front() ] + 1, bfs.push( *i );
		printf( dist[ to ] || from == to? "%d\n" : "Impossible\n", dist[ to ] );
	}
}
