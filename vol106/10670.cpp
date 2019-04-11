#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, begin, end, have, one, half;
	char s[ 20 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d\n", &begin, &end, &have );
		pair<int,string> stat[ 100 ];

		for( int i = 0; i < have; ++i )
		{
			scanf( "%[A-Z]:%d,%d\n", s, &one, &half );
			int cost = 0;
			for( int task = begin; task != end; )
				if( task / 2 >= end && ( task - task/2 ) * one > half )
					cost += half, task >>= 1;
				else
					cost += one, --task;
			stat[ i ] = make_pair( cost, string( s ) );
		}
		sort( stat, stat + have );

		printf( "Case %d\n", n );
		for( int i = 0; i < have; ++i )
			printf( "%s %d\n", stat[ i ].second.c_str(), stat[ i ].first );
	}
}
