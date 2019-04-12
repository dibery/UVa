#include<cstdio>
// bigmod

int cal( int b, int e, int m )
{
	int mod[ 31 ] = { b }, ans = 1;

	for( int i = 1; i < 31; ++i )
		mod[ i ] = mod[ i - 1 ] * mod[ i - 1 ] % m;
	for( int i = 0; i < 31; ++i )
		if( e & 1 << i )
			ans = ans * mod[ i ] % m;

	return ans;
}

int main()
{
	int T, len, pow, mod;

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d %d %d", &len, &pow, &mod ); ++t )
	{
		int ans = 0;
		for( int i = 0, n; i < len; ++i )
		{
			scanf( "%d", &n );
			n %= mod;
			ans = ( ans + pow % mod * n % mod * cal( len, pow - 1, mod ) % mod ) % mod;
		}
		printf( "Case %d: %d\n", t, ans );
	}
}
