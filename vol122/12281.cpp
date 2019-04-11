#include<bits/stdc++.h>
using namespace std;

int main()
{
	int fib[ 47 ] = { 0, 1 }, need[ 1001 ] = { 0 }, t;

	for( int i = 2; i < 47; ++i )
		fib[ i ] = fib[ i-1 ] + fib[ i-2 ];

	scanf( "%d", &t );
	for( int n = 1, dim; n <= t; ++n )
	{
		long long ans = 1;
		scanf( "%d", &dim );
		for( int i = 0, N; i < dim; ++i )
		{
			scanf( "%d", &N );
			int use = 0;
			for( int j = 46; j && N; --j )
				if( N >= fib[ j ] )
					N -= fib[ j ], ++use;
			ans *= use;
		}
		printf( "Case %d: %lld\n", n, ans );
	}
}
