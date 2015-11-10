#include<cstdio>
#include<vector>
#include<algorithm>
#define N 4096
using namespace std;

int t, bit[ N ] = { 0 }, ans[ N ] = { 0 };
char init[ 13 ];
vector<int> adj[ N ];
bool vis[ N ] = { true };

int dfs( int state )
{
	if( vis[ state ] )
		return ans[ state ];
	vis[ state ] = true;

	for( auto i: adj[ state ] )
		ans[ state ] = min( ans[ state ], dfs( i ) );
	return ans[ state ];
}

bool link( int a, int b ) // a -> b
{
	if( bit[ a ] - 1 != bit[ b ] )
		return false;
	int diff = a ^ b;
	return diff / ( diff & -diff ) == 7 && ( a & diff ) % 3 == 0;
}

int main()
{
	for( int i = 1; i < N; ++i )
		ans[ i ] = bit[ i ] = bit[ i ^ ( i & -i ) ] + 1;
	for( int i = 1; i < N; ++i )
		for( int j = 1; j < N; ++j )
			if( link( j, i ) )
				adj[ j ].push_back( i );
	for( int i = 1; i < N; ++i )
		dfs( i );

	for( scanf( "%d\n", &t ); t--; )
	{
		gets( init );
		replace( init, init + 12, '-', '0' );
		replace( init, init + 12, 'o', '1' );
		printf( "%d\n", ans[ strtol( init, NULL, 2 ) ] );
	}
}
