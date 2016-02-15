#include<iostream>
#include<queue>
#include<utility>
#include<climits>
using namespace std;
typedef pair<int,int> node;

int main()
{
	for( string s; cin >> s; )
	{
		int adj[ 26 ][ 26 ] = { { 0 } }, deg[ 26 ] = { 0 }, begin, end, ans = 0;

		do
		{
			++deg[ begin = s.front() - 'a' ];
			++deg[ end = s.back() - 'a' ];
			ans += adj[ begin ][ end ] = adj[ end ][ begin ] = s.size();
		}
		while( cin >> s && s != "deadend" );

		begin = end = -1;
		for( int i = 0; i < 26; ++i )
			if( deg[ i ] % 2 )
				begin = i, i = 26;
		if( begin != -1 )
		{
			for( int i = begin + 1; i < 26; ++i )
				if( deg[ i ] % 2 )
					end = i, i = 26;

			priority_queue<node,vector<node>,greater<node>> dij;
			int dist[ 26 ];

			fill( dist, dist + 26, INT_MAX );
			for( dij.emplace( dist[ begin ] = 0, begin ); !dij.empty(); )
				if( dist[ dij.top().second ] == INT_MAX || dij.top().second == begin )
				{
					int v = dij.top().second, d = dij.top().first;
					dij.pop();
					dist[ v ] = d;
					for( int i = 0; i < 26; ++i )
						if( adj[ v ][ i ] && dist[ i ] == INT_MAX )
							dij.emplace( d + adj[ v ][ i ], i );
				}
				else
					dij.pop();
			ans += dist[ end ];
		}

		cout << ans << endl;
	}
}
