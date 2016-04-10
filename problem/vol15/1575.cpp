#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int primes[ 30 ] = { 2 }, size = 1, times[ 30 ];
double Log[ 30 ], LIMIT = log( 2 ) * 63;
map<long long,long long> ans;

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

long long calc( int depth )
{
	long long factor[ 63 ] = { 0 }, v = 1;

	for( int i = 0; i < depth; ++i );
	for( int i = 0; i < 63; ++i )
		while( factor[ i ]-- )
			v *= primes[ i ];
	return v;
}

void gen( int exp, int idx = 0, double log_value = 0, int depth = 0 )
{
	for( times[ depth ] = exp; times[ depth ]; --times[ depth ] )
		if( log_value + times[ depth ] * Log[ idx ] < LIMIT )
		{
			long long val = 1, perm = calc( depth );
			for( int i = 0; i <= idx; ++i )
				for( int j = 0; j < times[ depth ]; ++j )
					val *= primes[ i ];
			if( ans.find( perm ) == ans.end() || ans[ perm ] > val )
				ans[ perm ] = val;
			gen( times[ depth ], idx + 1, log_value + times[ depth ] * Log[ idx ] );
		}
}

int main()
{
	for( int i = 3; i < 63; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;
	for( int i = 0; i < size; ++i )
		Log[ i ] = log( primes[ i ] );
	gen( 62 );
}
