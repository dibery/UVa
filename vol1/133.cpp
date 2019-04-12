#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	for( int n, k, m; scanf( "%d %d %d", &n, &k, &m ) && n; )
	{
		vector<pair<int,int>> leave;
		vector<int> L;
		int a = 0, b = n - 1;

		for( int i = 1; i <= n; ++i )
			L.push_back( i );
		--k, --m;

		while( !L.empty() )
		{
			a = ( a + k ) % L.size();
			b = ( b - m + 100 * L.size() ) % L.size();

			int ida = L[ a ], idb = L[ b ];
			leave.emplace_back( ida, idb );

			L.erase( L.begin() + max( a, b ) );
			if( a != b )
				L.erase( L.begin() + min( a, b ) );

			a = L.back() > ida? lower_bound( L.begin(), L.end(), ida ) - L.begin(): 0;
			b = L.front() > idb? L.size() - 1 : lower_bound( L.begin(), L.end(), idb ) - L.begin() - 1;
		}

		for( auto i = leave.begin(); i != leave.end(); ++i )
			if( i->first == i->second )
				printf( "%3d%c", i->first, next( i ) == leave.end()? '\n' : ',' );
			else
				printf( "%3d%3d%c", i->first, i->second, next( i ) == leave.end()? '\n' : ',' );
	}
}
