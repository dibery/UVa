#include<cstdio>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
	int t, size, mod, N[ 100000 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &size, &mod );
		long long ans = 0;
		vector<int> has[ mod ];
		map<int,int> div[ mod ];

		for( int i = 0; i < size; ++i )
		{
			scanf( "%d", N + i );
			++div[ ( N[ i ] % mod + mod ) % mod ][ N[ i ] / mod - ( N[ i ] < 0 ) ];
		}

		for( int i = 0; i < mod; ++i )
			for( map<int,int>::iterator j = div[ i ].begin(); j != div[ i ].end(); ++j )
				has[ i ].push_back( j->first );
		for( vector<int>::iterator i = has->begin(); i != has->end(); ++i )
			ans += distance( i + ( div[ 0 ][ *i ] == 1 ), has->end() );
		for( int i = 1; i < mod; ++i )
			for( vector<int>::iterator j = has[ i ].begin(); j != has[ i ].end(); ++j )
				if( mod > i * 2 )
					ans += distance( lower_bound( has[ mod - i ].begin(), has[ mod - i ].end(), *j ), has[ mod - i ].end() );
				else if( mod == i * 2 )
					ans += distance( j + ( div[ i ][ *j ] == 1 ), has[ i ].end() );
				else
					ans += distance( lower_bound( has[ mod - i ].begin(), has[ mod - i ].end(), *j + 1 ), has[ mod - i ].end() );

		printf( "Case %d: %lld\n", n, ans );
	}
}
