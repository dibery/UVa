#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	long long pow2[ 60 ] = { 1 }, n, t;

	for( int i = 1; i < 60; ++i )
		pow2[ i ] = pow2[ i - 1 ] << 1;

	scanf( "%lld", &t );
	for( int T = 1; T <= t; ++T )
	{
		scanf( "%lld", &n );
		printf( "Case %d: %ld\n", T, upper_bound( pow2, pow2 + 60, n ) - pow2 );
	}
}
