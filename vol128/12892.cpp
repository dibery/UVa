#include<cstdio>
#include<vector>
#include<numeric>
using namespace std;

int dfs( int node, vector<int>* child, vector<int>* size, int* sum )
{
	for( size_t i = 0; i < child[ node ].size(); ++i )
	{
		int s = dfs( child[ node ][ i ], child, size, sum );
		size[ node ].push_back( s );
		sum[ node ] += s;
	}
	return ++sum[ node ];
}

int main()
{
	int t, node, parent[ 10001 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		vector<int> child[ 10001 ], size[ 10001 ];
		int sum[ 10001 ] = { 0 };

		scanf( "%d", &node );
		for( int i = 1; i <= node; ++i )
		{
			scanf( "%d", parent + i );
			child[ parent[ i ] ].push_back( i );
		}
		dfs( 0, child, size, sum );
		printf( "Forest#%d: ", n );
		for( int i = 1, now = 0; i <= node; ++i, now = 0 )
		{
			for( size_t j = 0; j < child[ i ].size(); ++j )
				now += size[ i ][ j ] * ( sum[ i ] -= size[ i ][ j ] );
			printf( "%d%c", now, i == node? '\n' : ' ' );
		}
	}
}
