#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
inline int GCD( int a, int b ) { return a % b ? GCD( b, a % b ) : b; }
inline int LCM( int a, int b ) { return a * b / GCD( a, b ); }

int main()
{
	int type, table, h[ 50 ], build;

	while( scanf( "%d %d", &type, &table ) && type )
	{
		for( int i = 0; i < type; ++i )
			scanf( "%d", h+i );
		for( int i = 0; i < table; ++i )
		{
			int m = 0, M = INT_MAX;
			scanf( "%d", &build );
			for( int a = 0; a < type; ++a )
				for( int b = a+1; b < type; ++b )
					for( int c = b+1; c < type; ++c )
						for( int d = c+1; d < type; ++d )
						{
							int lcm = LCM( h[ a ], LCM( h[ b ], LCM( h[ c ], h[ d ] ) ) );
							m = max( m, build / lcm * lcm );
							M = min( M, build / lcm * lcm + lcm * ( build % lcm != 0 ) );
						}
			printf( "%lld %lld\n", m, M );
		}
	}
}
