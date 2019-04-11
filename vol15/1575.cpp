#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

const int N = 63, size = 18;
int primes[ N ] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 }, show[ N ];
double Log[ N ], LIMIT = log( 2 ) * N;
map<long long,long long> ans;

long long calc( int depth )
{
	long long factor[ N ] = { 0 }, v = 1, sum = 0;

	for( int i = 0; i <= depth; ++i )
	{
		sum += show[ i ];
		for( int j = 2; j <= show[ i ]; ++j )
			for( int k = j, p = 0; k > 1; ++p )
				while( k % primes[ p ] == 0 )
					--factor[ p ], k /= primes[ p ];
	}
	for( int i = 2, j = 2; i <= sum; j = ++i )
		for( int p = 0; j > 1; ++p )
			while( j % primes[ p ] == 0 )
				++factor[ p ], j /= primes[ p ];
	for( int i = 0; i < N; ++i )
		while( factor[ i ]-- )
			v *= primes[ i ];
	return v;
}

void gen( int exp, int idx = 0, double log_value = 0 )
{
	for( show[ idx ] = exp; show[ idx ]; --show[ idx ] )
		if( log_value + show[ idx ] * Log[ idx ] < LIMIT )
		{
			long long val = 1, perm = calc( idx );
			for( int i = 0; i <= idx; ++i )
				for( int j = 0; j < show[ i ]; ++j )
					val *= primes[ i ];
			if( ans.find( perm ) == ans.end() || ans[ perm ] > val )
				ans[ perm ] = val;
			gen( show[ idx ], idx + 1, log_value + show[ idx ] * Log[ idx ] );
		}
}

int main()
{
	for( int i = 0; i < size; ++i )
		Log[ i ] = log( primes[ i ] );
	gen( N-1 );
	for( long long n; ~scanf( "%lld", &n ); printf( "%lld %lld\n", n, ans[ n ] ) );
}
