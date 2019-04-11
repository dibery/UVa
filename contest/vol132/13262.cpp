#include<cstdio>
#include<unordered_map>
using namespace std;

int main()
{
	for( int M, pos[ 3 ], neg[ 3 ]; ~scanf( "%d %d %d %d %d %d %d", &M, pos, neg, pos + 1, neg + 1, pos + 2, neg + 2 ); )
	{
		unordered_map<int,int> sol;
		int ans = 0;

		sol.reserve( 2000000 );
		for( int i = 1; i <= M; ++i )
			for( int j = 1; j <= M; ++j )
				for( int k = 1; k <= M; ++k )
					++sol[ i * pos[ 0 ] + j * pos[ 1 ] + k * pos[ 2 ] ];
		for( int i = 1; i <= M; ++i )
			for( int j = 1; j <= M; ++j )
				for( int k = 1; k <= M; ++k )
				{
					try
					{
						ans += sol[ i * neg[ 0 ] + j * neg[ 1 ] + k * neg[ 2 ] ];
					}
					catch(...){}
				}

		printf( "%d %d\n", ans, int( sol.size() ) );
	}
}
