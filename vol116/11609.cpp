#include<cstdio>

long long int calc( int base, int exp, int mod )
{
	long long int cal[ 32 ], ans;

	if( base == 1 || exp == 0 )
		return 1;
	if( exp == 1 )
		return base % mod;
	else
	{
		*cal = ans = 1;
		cal[ 1 ] = base % mod;
		for( int i = 2; i < 32; ++i )
			cal[ i ] = ( cal[ i-1 ] * cal[ i-1 ] ) % mod;
		for( int i = 0; i < 31; ++i )
			if( 1 << i & exp )
				ans = ( ans * cal[ i+1 ] ) % mod;
		return ans;
	}
}

int main()
{
	int t, n;
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d", &n );
		printf( "Case #%d: %lld\n", i, n * calc( 2, n-1, 1000000007 ) % 1000000007 );
	}

	return 0;
}
