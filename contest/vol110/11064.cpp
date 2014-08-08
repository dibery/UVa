#include<cstdio>
#include<climits>
int prime[ 5000 ] = { 2 }, size = 1, pow2[ 31 ] = { 1 };
bool isprime[ 46341 ] = { false, false, true };

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
	int total = 0, list[ 20 ] = { 0 }, s = 0, cp = n, factor = 1;

	for( int i = 0; i < size && prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
		{
			int tmp = 0;
			list[ s++ ] = prime[ i ];
			while( n % prime[ i ] == 0 )
				n /= prime[ i ], ++tmp;
			factor *= tmp+1;
		}
	if( n > 1 )
		list[ s++ ] = n, factor *= 2;
	n = cp;
	for( int i = 1; i < pow2[ s ]; ++i )
		if( count( i ) % 2 == 0 )
			total -= n / mul( list, i, s );
		else
			total += n / mul( list, i, s );
	return total - factor + 1;
}

int main()
{
	int n;

	for( int i = 1; i < 31; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1;
	for( int i = 3; i < 46340; i += 2 )
		if( check( i ) )
			prime[ size++ ] = i, isprime[ i ] = true;

	while( scanf( "%d", &n ) == 1 )
		printf( "%d\n", n == 1? 0 : calc( n ) );
}
