#include<cstdio>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef set<int> usi;

int main()
{
	for( int v, e; scanf( "%d %d", &v, &e ) && v + e; )
	{
		usi *cover = new usi[ v ], *covered = new usi[ v ];
		queue<int> done;
		bool vis[ 1000000 ] = { false };
		vector<int> order;

		for( int i = 0, a, b; i < e && scanf( "%d %d", &a, &b ); ++i )
			cover[ --a ].insert( --b ), covered[ b ].insert( a );
		for( int i = 0; i < v; ++i )
			if( covered[ i ].empty() )
				done.push( i ), vis[ i ] = true;

		while( !done.empty() )
		{
			order.push_back( done.front() );
			for( auto& i: cover[ done.front() ] )
			{
				covered[ i ].erase( done.front() );
				if( covered[ i ].empty() && !vis[ i ] )
					done.push( i ), vis[ i ] = true;
			}
			done.pop();
		}

		if( order.size() == v )
			for( int& i: order )
				printf( "%d\n", i + 1 );
		else
			puts( "IMPOSSIBLE" );

		delete[] cover;
		delete[] covered;
	}
}
