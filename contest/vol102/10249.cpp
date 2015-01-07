#include<cstdio>
#include<algorithm>
using namespace std;
typedef const pair<int,int>& P;

int main()
{
	int m, n, t[ 70 ], ans[ 70 ][ 100 ];
	pair<int,int> table[ 200 ], team[ 70 ];

	while( scanf( "%d %d", &m, &n ) && m+n )
	{
		for( int i = 0; i < m; ++i )
			scanf( "%d", t+i ), team[ i ] = make_pair( i, t[ i ] );
		const int M = *max_element( t, t+m );
		for( int i = 0, tmp; i < n; ++i )
			scanf( "%d", &tmp ), table[ i ] = make_pair( i+1, tmp );

		for( int i = 0; i < m && M <= n; ++i )
		{
			sort( table, table+n, [] ( P a, P b ) { return a.second > b.second; } );
			for( int j = 0; j < team[ i ].second; ++j )
				ans[ team[ i ].first ][ j ] = table[ j ].first, --table[ j ].second;
		}
		sort( table, table+n, [] ( P a, P b ) { return a.second > b.second; } );

		printf( "%d\n", M <= n && table[ n-1 ].second >= 0 );
		if( M <= n && table[ n-1 ].second >= 0 )
			for( int i = 0; i < m; ++i )
				for( int j = 0; j < t[ i ]; ++j )
					printf( "%d%c", ans[ i ][ j ], j == t[ i ]-1? '\n' : ' ' );
	}
}
