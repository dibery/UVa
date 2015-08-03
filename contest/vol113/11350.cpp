#include<cstdio>
#include<utility>
using namespace std;

int main()
{
	int t;
	char act[ 99 ];

	for( scanf( "%d %s", &t, act ); t--; scanf( "%s", act ) )
	{
		pair<long long,long long> L( 0, 1 ), M( 1, 1 ), R( 1, 0 );

		for( int i = 0; act[ i ]; ++i )
			if( act[ i ] == 'L' )
				R = M, M = make_pair( L.first + R.first, L.second + R.second );
			else
				L = M, M = make_pair( L.first + R.first, L.second + R.second );
		printf( "%lld/%lld\n", M.first, M.second );
	}
}
