#include<cstdio>

bool prime( int n, int *p )
{
	for( int i = 0; p[ i ] * p[ i ] <= n && p[ i ]; ++i )
		if( n % p[ i ] == 0 )
			return false;
	return true;
}
int big_mod( long long int base, long long int exp, long long int mod )
{
	long long int cal[ 32 ], ans;

	*cal = ans = 1;
	cal[ 1 ] = base % mod;
	for( int i = 2; i < 32; ++i )
		cal[ i ] = ( cal[ i-1 ] * cal[ i-1 ] ) % mod;
	for( int i = 0; i < 31; ++i )
		if( 1 << i & exp )
			ans = ( ans * cal[ i+1 ] ) % mod;
	return (int)ans;
}

int main()
{
	int pow, base, pri[ 3401 ] = { 2 }, put = 0;
	for( int i = 3; i <= 31622; i += 2 )
		if( prime( i, pri ) )
			pri[ ++put ] = i;

	while( scanf( "%d %d", &pow, &base ) && pow )
		puts( !prime( pow, pri ) && big_mod( base, pow, pow ) == base? "yes" : "no" );

	return 0;
}
