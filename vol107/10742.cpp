#include<cstdio>
#include<algorithm>
using namespace std;

int primes[ 100000 ] = { 2 }, size = 1;

bool isprime( int n )
{
	for( int i = 0; i < size && primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int way( int n )
{
	int ans = 0;
	for( int first = 1, second = 0; second >= 0; ++first )
	{
		while( primes[ first ] + primes[ second ] < n && second + 1 < first )
			++second;
		while( primes[ first ] + primes[ second ] > n && second >= 0 )
			--second;
		ans += second + 1;
	}
	return ans;
}

int main()
{
	for( int i = 3; i <= 1000003; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;
	for( int n, t = 0; scanf( "%d", &n ) && n; )
		printf( "Case %d: %d\n", ++t, way( n ) );
}
