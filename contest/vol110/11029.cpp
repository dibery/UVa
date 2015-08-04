#include<cstdio>
#include<cmath>

int bigmod( int base, int exp, int mod = 1000 )
{
	int cal[ 32 ] = { 0, base % mod }, ans = 1;

	for( int i = 2; i < 32; ++i )
		cal[ i ] = ( cal[ i-1 ] * cal[ i-1 ] ) % mod;
	for( int i = 0; i < 31; ++i )
		if( 1 << i & exp )
			ans = ( ans * cal[ i+1 ] ) % mod;
	return ans;
}

int main()
{
	int b, e;
	for( scanf( "%*s" ); scanf( "%d %d", &b, &e ) == 2; )
	{
		double tmp = b, expo = modf( log10( tmp ) * e, &tmp );
		printf( "%d...%03d\n", (int)pow( 10, expo+2 ), bigmod( b % 1000, e ) );
	}
}
