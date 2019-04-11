#include<cstdio>
#include<cstring>

bool adj[ 3001 ][ 3001 ];

int main()
{
	int t, V, E;

	for( scanf( "%d", &t ); t--; memset( adj, false, sizeof( adj ) ) )
	{
		scanf( "%d %d", &V, &E );
		for( int a, b, i = 0; i < E && scanf( "%d %d", &a, &b ); ++i )
			++adj[ a ][ b ], ++adj[ b ][ a ];

		long long ans = 0;

		for( int i = 1; i < V; ++i )
			for( int j = i + 1; j < V; ++j )
				if( adj[ i ][ j ] )
					for( int k = j + 1; k <= V; ++k )
						ans += adj[ i ][ k ] && adj[ j ][ k ];

		printf( "%lld\n", ans );
	}
}
