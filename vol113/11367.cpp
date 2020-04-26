#include<bits/stdc++.h>
using namespace std;

list<pair<pair<int,int>,int>> cost[ 1000 ][ 101 ];
int dist[ 1000 ][ 101 ];

int main()
{
	int city, road, price[ 1000 ], query;

	scanf( "%d %d", &city, &road );
	for( int i = 0; i < city; ++i )
		scanf( "%d", price + i );
	for( int i = 0; i < city; ++i )
		for( int j = 1; j < 101; ++j )
			cost[ i ][ j - 1 ].emplace_back( make_pair( i, j ), price[ i ] );
	for( int s, t, d; road-- && scanf( "%d %d %d", &s, &t, &d ); )
		for( int i = d; i < 101; ++i )
		{
			cost[ s ][ i ].emplace_back( make_pair( t, i - d ), 0 );
			cost[ t ][ i ].emplace_back( make_pair( s, i - d ), 0 );
		}
	scanf( "%d", &query );
	for( int s, t, c; query-- && scanf( "%d %d %d", &c, &s, &t ); )
	{
		memset( dist, -1, sizeof( dist ) );
		priority_queue<pair<int,pair<int,int>>> sssp;
		int ans = -1;

		for( sssp.emplace( 0, make_pair( s, 0 ) ); !sssp.empty() && !~ans; )
		{
			auto top = sssp.top();
			int d = -top.first, city = top.second.first, fuel = top.second.second;
			sssp.pop();
			if( ~dist[ city ][ fuel ] )
				continue;
			dist[ city ][ fuel ] = d;
			if( city == t )
				ans = d;
			for( auto& i: cost[ city ][ fuel ] )
				if( i.first.second <= c && !~dist[ i.first.first ][ i.first.second ] )
					sssp.emplace( -d - i.second, i.first );
		}
		printf( ~ans? "%d\n" : "impossible\n", ans );
	}
}
