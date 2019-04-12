#include<cstdio>
#include<climits>
const int N = 2000000;
int prime[ 3410 ] = { 2 }, size = 1, pow2[ 15 ] = { 1 };
int phi[ N+1 ], one[ 256 ], sodf[ N+1 ], dep[ N+1 ];
bool isprime[ 31622 ] = { false, false, true };

bool check( int );
int count( int ), calc( int ), depth( int ), mul( int*, int, int );

int main()
{
	int low, high, t;

	for( int i = 1; i < 15; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1;
	for( int i = 0; i < 256; ++i )
		one[ i ] = count( i );
	for( int i = 3; i*i <= N; i += 2 )
		if( check( i ) )
			prime[ size++ ] = i, isprime[ i ] = true;
	for( int i = 1; i <= N; ++i )
		phi[ i ] = i - calc( i );
	for( int i = 2; i <= N; ++i )
		dep[ i ] = depth( i );
	for( int i = 2; i <= N; ++i )
		sodf[ i ] = sodf[ i-1 ] + dep[ i ];

	for( scanf( "%d", &t ); t; --t )
		scanf( "%d %d", &low, &high ) == 2, printf( "%d\n", sodf[ high ] - sodf[ low-1 ] );
}

bool check( int n )
{
	for( int i = 0; i < size && prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int count( int n )
{
	int ans = 0;
	while( n )
		ans += n & 1, n >>= 1;
	return ans;
}

int mul( int* prime, int pos, int size )
{
	long long int ans = 1;
	for( int i = 0; i < size && ans < INT_MAX; ++i )
		if( pos & 1 << i )
			ans *= prime[ i ];
	return ans < INT_MAX? ans : INT_MAX;
}

int calc( int n )
{
	int total = 0, list[ 20 ] = { 0 }, s = 0, cp = n;

	for( int i = 0; i < size && prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
		{
			list[ s++ ] = prime[ i ];
			while( n % prime[ i ] == 0 )
				n /= prime[ i ];
		}
	if( n > 1 )
		list[ s++ ] = n;
	n = cp;
	for( int i = 1; i < pow2[ s ]; ++i )
		if( one[ i ] % 2 == 0 )
			total -= n / mul( list, i, s );
		else
			total += n / mul( list, i, s );
	return total;
}

int depth( int n )
{
	if( dep[ n ] )
		return dep[ n ];
	if( n == 1 )
		return 0;
	return depth( phi[ n ] ) + 1;
}
