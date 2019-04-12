#include<bits/stdc++.h>
using namespace std;

struct patch
{
	int time, existent, nonexistent, broke, fix;
	patch()
	{
		char e[ 21 ], b[ 21 ];
		scanf( "%d %s %s", &time, e, b );
		existent = nonexistent = fix = broke = 0;
		for( int i = 0; e[ i ]; ++i )
		{
			if( e[ i ] == '-' )
				nonexistent |= 1 << i;
			else if( e[ i ] == '+' )
				existent |= 1 << i;
			if( b[ i ] == '-' )
				fix |= 1 << i;
			else if( b[ i ] == '+' )
				broke |= 1 << i;
		}
	}
	bool ok( int state )
	{
		return ( nonexistent & state ) == 0 && ( existent & state ) == existent;
	}
	int apply( int state )
	{
		return state & ~fix | broke;
	}
};

int main()
{
	for( int B, P, t = 0; scanf( "%d %d", &B, &P ) && B; )
	{
		patch *patches = new patch[ P ];
		int len = 1 << B, *dist = new int[ len ];
		fill( dist, dist + len, INT_MAX );
		typedef pair<int,int> pii;
		priority_queue<pii, vector<pii>, greater<pii>> sssp;
		for( sssp.emplace( 0, len - 1 ); !sssp.empty() && *dist == INT_MAX; )
		{
			auto top = sssp.top();
			sssp.pop();
			if( dist[ top.second ] != INT_MAX )
				continue;
			dist[ top.second ] = top.first;
			for( int i = 0; i < P; ++i )
				if( patches[ i ].ok( top.second ) )
						sssp.emplace( top.first + patches[ i ].time, patches[ i ].apply( top.second ) );
		}
		printf( "Product %d\n", ++t );
		if( *dist == INT_MAX )
			puts( "Bugs cannot be fixed.\n" );
		else
			printf( "Fastest sequence takes %d seconds.\n\n", *dist );
		delete[] dist;
		delete[] patches;
	}
}
