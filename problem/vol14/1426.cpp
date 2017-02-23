#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	for( long long x, n, r, t = 0; scanf( "%lld %lld %lld", &x, &n, &r ) && n; )
	{
		set<long long> roots;

		r = min( r, n - r );
		for( int i = 1; i * i <= n; ++i )
			if( n % i == 0 )
				for( long long step = n / i, delta = step; delta <= n; delta += step )
				{
					if( delta * ( delta + 2 * r ) % n == 0 )
						roots.insert( ( r + delta ) % n );
					if( delta * ( delta - 2 * r ) % n == 0 )
						roots.insert( ( r + delta - 2 * r + n ) % n );
				}
		printf( "Case %lld:", ++t );
		for( auto i: roots )
			printf( " %lld", i );
		puts( "" );
	}
}
