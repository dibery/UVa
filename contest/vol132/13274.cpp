#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;

int count( vector<int> *e, bool *vis, int lim, int v = 1 )
{
	vector<int> child;

	vis[ v ] = true;
	for( int c: e[ v ] )
		if( !vis[ c ] )
			child.push_back( count( e, vis, lim, c ) );

	if( child.size() < lim )
		return 1;
	sort( child.begin(), child.end(), greater<int>() );
	return accumulate( child.begin(), child.begin() + lim, 0 ) + 1;
}

int main()
{
	int T;

	scanf( "%d", &T );
	for( int t = 1, v, child; t <= T && scanf( "%d %d", &v, &child ); ++t )
	{
		vector<int> edge[ 1001 ];
		bool vis[ 1001 ] = { false };

		for( int i = 1, m, n; i < v && scanf( "%d %d", &m, &n ); ++i )
			edge[ m ].push_back( n ), edge[ n ].push_back( m );

		printf( "Case %d: %d\n", t, count( edge, vis, child ) );
	}
}
