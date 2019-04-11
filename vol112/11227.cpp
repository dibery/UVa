#include<cstdio>
#include<set>
#include<utility>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;

int main()
{
	int t, N, i1, f1, i2, f2;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		set<pii> pt;
		int M = 0;

		for( scanf( "%d", &N ); N--; pt.insert( pii( i1 * 100 + f1, i2 * 100 + f2 ) ) )
			scanf( "%d.%d %d.%d", &i1, &f1, &i2, &f2 );
		for( auto i = pt.begin(); i != pt.end(); ++i )
			for( auto j = next( i ); j != pt.end(); ++j )
			{
				int on = 2;
				for( auto k = next( j ); k != pt.end(); ++k )
					on += ( j->y - i->y ) * ( k->x - i->x ) == ( k->y - i->y ) * ( j->x - i->x );
				M = M > on? M : on;
			}

		if( pt.size() == 1 )
			printf( "Data set #%d contains a single gnu.\n", n );
		else
			printf( "Data set #%d contains %u gnus, out of which a maximum of %d are aligned.\n", n, pt.size(), M );
	}
}
