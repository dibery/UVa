#include<cstdio>

int calc( int f )
{
	int limit = f/5*5, ans = 1, k = f/5, two_mod_five[] = { 1, 2, 4, 3 };

	for( int i = limit+1; i <= f; ++i )
		ans = ans * ( i % 5 ) % 5;
	return ans * two_mod_five[ k % 4 ] * ( k? calc( k ) : 1 ) % 5;
}

int times( int n, int div )
{
	int t = 0;
	while( n % div == 0 )
		n /= div, ++t;
	return t;
}

int main()
{
	int two_mod_five[] = { 0, 6, 2, 8, 4 }, n, m, mul, div, pow2[ 31 ] = { 1 }, pow5[ 31 ] = { 1 };
	char table[][5] = { "2468", "6284", "8642", "2468", "4826" };
	for( int i = 1; i < 31; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1, pow5[ i ] = pow5[ i-1 ] * 5;

	while( scanf( "%d %d", &n, &m ) == 2 )	//P(N,M)
	{
		int ans = 1, two[ 300 ] = { 0 }, five[ 300 ] = { 0 }, T = 0, F = 0;
		if( m < 300 )
		{
			for( int i = 0; i < m; ++i )
				T += two[ i ] = times( n-i, 2 ), F += five[ i ] = times( n-i, 5 );
			if( T < F )
				for( int i = 0; i < m; ++i )
					ans = ans * ( n-i >> two[ i ] ) % 10;
			else if( T == F )
				for( int i = 0; i < m; ++i )
					ans = ans * ( (n-i) / pow2[ two[ i ] ] / pow5[ five[ i ] ] ) % 10;
		}
		if( m >= 300 || T > F )
		{
			mul = two_mod_five[ calc( n ) ];
			div = n-m > 1? two_mod_five[ calc( n-m ) ] : 1;
			ans = table[ div/2 ][ mul/2 - 1 ] - '0';
		}
		printf( "%d\n", ans );
	}
}
