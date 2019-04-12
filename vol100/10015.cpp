#include<cstdio>
#include<vector>
using namespace std;

vector<int> primes( 1, 2 );

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int joseph( int man, int step_idx )
{
	return man == 1? 0 : ( primes[ step_idx ] + joseph( man - 1, step_idx + 1 ) ) % man;
}

int main()
{
	for( int i = 3; primes.size() < 3501; i += 2 )
		if( isprime( i ) )
			primes.push_back( i );
	for( int n; scanf( "%d", &n ) && n; )
		printf( "%d\n", joseph( n, 0 ) + 1 );
	return 0;
}
