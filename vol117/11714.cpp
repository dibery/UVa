#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n, pow2[ 40 ] = { 1 };

	for( int i = 1; i < 40; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1;

	while( scanf( "%lld", &n ) == 1 )
	{
		--n;
		printf( "%lld\n", n + ( upper_bound( pow2, pow2+40, n ) - pow2 - 1 ) );
	}
}
