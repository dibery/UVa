#include<cstdio>

void egcd( int a, int b, int& x, int& y )
{
	if( b == 0 )
		x = 1, y = 0;
	else
		egcd( b, a%b, y, x ), y -= a / b * x;
}

long long int big_mod( long long int base, long long int exp, long long int mod )
{
	if( base == 0 || mod == 1 )
		return 0;
	else if( base == 1 || exp == 0 )
		return 1;
	else if( exp == 1 )
		return base % mod;
	else
	{
		long long int ans, cal[ 64 ];
		*cal = ans = 1;
		cal[ 1 ] = base % mod;
		for( int i = 2; i < 64; ++i )
			cal[ i ] = ( cal[ i-1 ] * cal[ i-1 ] ) % mod;
		for( int i = 0; i < 64; ++i )
			if( 1ll << i & exp )
				ans = ( ans * cal[ i+1 ] ) % mod;
		return ans;
	}
}

int main()
{
	int n, e, c, p, q, phi, d, x, y;

	while( scanf( "%d %d %d", &n, &e, &c ) == 3 )
	{
		for( p = 3; n % p; p += 2 );
		q = n / p;
		phi = (p-1) * (q-1);
		egcd( e, phi, x, y );
		d = phi + x;
		printf( "%lld\n", big_mod( c, d, n ) );
	}
}
