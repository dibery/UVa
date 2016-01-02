#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;

int main()
{
	int t, size, n[ 1000 ], ans, nonzero, now;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%d", n + i );

		ans = *n / 3;
		*n %= 3;
		for( nonzero = 0; nonzero < size && !n[ nonzero ]; ++nonzero );

		for( int i = 1; i < size; ++i )
		{
			now = min( n[ i ], n[ i - 1 ] / 2 );
			ans += now;
			n[ i ] -= now;
			n[ i - 1 ] -= now * 2;

			now = min( n[ i ] / 2, accumulate( n + nonzero, n + i, 0 ) );
			while( now && nonzero < i )
				if( n[ nonzero ] <= now )
				{
					ans += n[ nonzero ];
					now -= n[ nonzero ];
					n[ i ] -= 2 * n[ nonzero ];
					n[ nonzero++ ] = 0;
				}
				else
				{
					ans += now;
					n[ nonzero ] -= now;
					n[ i ] -= now * 2;
					now = 0;
				}

			ans += n[ i ] / 3;
			n[ i ] %= 3;
		}
		printf( "%d\n", ans );
	}
}
