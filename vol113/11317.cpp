#include<cstdio>
#include<cmath>
#include<cfloat>

const int N = 1000001;
int primes[ 305 ] = { 2 }, size = 1;
long long phi[ N ];
double gcd[ N ], lcm[ N ];

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

void all_factor( int p[], int t[], int s, int f[], int& fs, int dep = 0, int n = 1 )
{
	if( dep == s )
		f[ fs++ ] = n;
	else
		for( int i = 0, mul = 1; i <= t[ dep ]; ++i, mul *= p[ dep ] )
			all_factor( p, t, s, f, fs, dep + 1, n * mul );
}

int main()
{
	for( int i = 3; i * i <= N; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;

	for( int i = 2; i < N; ++i )
	{
		phi[ i ] = i;
		for( int j = 0; primes[ j ] * primes[ j ] <= i && j < size; ++j )
			if( i % primes[ j ] == 0 )
			{
				int t = i;
				while( t % primes[ j ] == 0 )
					t /= primes[ j ];
				phi[ i ] = phi[ i ] / primes[ j ] * ( primes[ j ] - 1 );
				if( t > 1 )
					phi[ i ] = phi[ i ] * phi[ t ] / t;
				break;
			}
		phi[ i ] -= phi[ i ] == i;
	}

	for( int i = 2; i < N; ++i )
	{
		int t[ 9 ] = { 0 }, p[ 9 ] = { 0 }, s = 0, n = i, factor[ 360 ], fs = 0;

		gcd[ i ] = gcd[ i - 1 ]? gcd[ i - 1 ] : DBL_EPSILON;
		lcm[ i ] = lcm[ i - 1 ] + log10( i );

		for( int j = 0; primes[ j ] * primes[ j ] <= n && j < size; ++j )
			if( n % primes[ j ] == 0 )
			{
				p[ s ] = primes[ j ];
				while( n % primes[ j ] == 0 )
					n /= primes[ j ], ++t[ s ];
				++s;
			}
		if( n > 1 )
			p[ s ] = n, t[ s++ ] = 1;

		if( i > n )
		{
			all_factor( p, t, s, factor, fs );
			for( int j = 1; j < fs; ++j )
				gcd[ i ] += log10( factor[ j ] ) * phi[ i / factor[ j ] ];
		}
	}

	for( int n, t = 0; scanf( "%d", &n ) && n; )
		printf( "Case %d: %.0f %.0f\n", ++t, ceil( gcd[ n ] / 100 ), ceil( ( lcm[ n ] * ( n - 1 ) - gcd[ n ] ) / 100 ) );
}
