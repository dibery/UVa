#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

bool check( map<pair<int,int>,int>& stat, int a, int b, int c )
{
	map<pair<int,int>,int> test;
	test[ make_pair( a, b ) ] += 2;
	test[ make_pair( b, c ) ] += 2;
	test[ make_pair( a, c ) ] += 2;
	return test == stat;
}

int main()
{
	for( pair<int,int> plane[ 6 ]; cin >> plane->x >> plane->y; )
	{
		set<int> len;
		map<pair<int,int>,int> stat;

		for( int i = 1; i < 6; ++i )
			cin >> plane[ i ].x >> plane[ i ].y;
		for( auto& p: plane )
		{
			if( p.x > p.y )
				swap( p.x, p.y );
			len.insert( p.x );
			len.insert( p.y );
			++stat[ p ];
		}

		vector<int> l( len.begin(), len.end() );
		if( len.size() == 1 )
			puts( "POSSIBLE" );
		else if( len.size() == 2 )
			puts( check( stat, l[ 0 ], l[ 1 ], l[ 1 ] ) || check( stat, l[ 0 ], l[ 0 ], l[ 1 ] )? "POSSIBLE" : "IMPOSSIBLE" );
		else if( len.size() == 3 )
			puts( check( stat, l[ 0 ], l[ 1 ], l[ 2 ] )? "POSSIBLE" : "IMPOSSIBLE" );
		else
			puts( "IMPOSSIBLE" );
	}
}
