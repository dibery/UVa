#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, size, k, c;
	long long int n[ 100000 ] = { 0 };

	scanf( "%d", &t );
	for( int s = 1; s <= t; ++s )
	{
		scanf( "%d %d %d %lld", &k, &c, &size, n );
		for( int i = 1; i < size; ++i )
			n[ i ] = ( k * n[ i-1 ] + c ) % 1000007;
		sort( n, n+size );
		long long int ans = 0;
		for( int i = 0; i < size; ++i )
			ans += i * n[ i ] - ( size-i-1 ) * n[ i ];
		printf( "Case %d: %lld\n", s, ans );
	}
}
