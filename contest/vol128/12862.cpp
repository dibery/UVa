#include<bits/stdc++.h>
using namespace std;

bool vis[ 100000 ], stand[ 100000 ];
int back[ 100000 ], longest;
map<int,int> path[ 100000 ];

int dfs_go_back( int pos = 0, int depth = 0 )
{
	if( vis[ pos ] )
		return back[ pos ];
	++vis[ pos ];
	if( stand[ pos ] )
		longest = max( longest, depth );

	for( map<int,int>::iterator i = path[ pos ].begin(); i != path[ pos ].end(); ++i )
	if( !vis[ i->first ] && ( dfs_go_back( i->first, depth + path[ i->first ][ pos ] ) || stand[ i->first ] ) )
		back[ pos ] += back[ i->first ] + path[ i->first ][ pos ];

	return back[ pos ];
}

int main()
{
	for( int N, F; scanf( "%d %d", &N, &F ) == 2; )
	{
		memset( vis, false, sizeof( vis ) );
		memset( stand, false, sizeof( stand ) );
		memset( back, longest = 0, sizeof( back ) );
		for( int i = 0; i < N; ++i )
			path[ i ].clear();

		for( int i = 1, from, to, energy; i < N; ++i )
		{
			scanf( "%d %d %d", &from, &to, &energy );
			--from, --to;
			path[ from ][ to ] = 0, path[ to ][ from ] = energy;
		}

		for( int i = 0, p; i < F; ++i )
			scanf( "%d", &p ), ++stand[ --p ];

		printf( "%d\n", dfs_go_back() - longest );
	}
}
