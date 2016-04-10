#include<cstdio>
#include<cmath>
#include<algorithm>

int p, a, b, c, d, n;
double price[ 1000001 ], min[ 1000001 ];

int main()
{
	while( scanf( "%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n ) == 6 )
	{
		double ans = 0;
		for( int i = 1; i <= n; ++i )
			price[ i ] = p * ( sin( a * i + b ) + cos( c * i + d ) + 2 );
		min[ n ] = price[ n ];
		for( int i = n - 1; i; --i )
			min[ i ] = std::min( min[ i + 1 ], price[ i ] );
		for( int i = 1; i <= n; ++i )
			ans = std::max( ans, price[ i ] - min[ i ] );
		printf( "%f\n", ans );
	}
}
