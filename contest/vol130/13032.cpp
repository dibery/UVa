#include<cstdio>
#include<algorithm>
using namespace std;

int calc( int len[], int n )
{
	for( int i = 0; i < n; ++i )
		if( len[ i ] < i + 1 )
			return 0;
	long long ans = 1;
	for( int i = 0; i < n; ++i )
		ans = ans * ( len[ i ] - i ) % 1000000007;
	return ans;
}

int main()
{
	int t, n, len[ 100 ];

	scanf( "%d", &t );
	for( int m = 1; m <= t; ++m )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; ++i )
			scanf( "%d", len + i );
		sort( len, len + n );
		printf( "Case %d: %d\n", m, calc( len, n ) );
	}
}
