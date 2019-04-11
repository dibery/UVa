#include<iostream>
#include<map>
#include<cmath>
using namespace std;

const int N = 20000001;
long long ans[ N ], mslcm[ N ];
int primes[ 610 ] = { 2 }, size = 1;

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i * i < N; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;
	mslcm[ 1 ] = 1;
	for( int i = 2; i < N; ++i )
	{
		long long div = 1;
		int t = i, p;
		for( int j = 0; j < size && primes[ j ] * primes[ j ] <= i; ++j )
			if( t % primes[ j ] == 0 )
			{
				p = primes[ j ];
				while( t % p == 0 )
					t /= p, div *= p;
				break;
			}
		if( t < i )
			mslcm[ i ] = mslcm[ t ] * ( div * p - 1 ) / ( p - 1 );
		else
			mslcm[ i ] = i + 1;
	}
	for( int i = 2; i < N; ++i )
		ans[ i ] = ans[ i - 1 ] + mslcm[ i ];
	for( int i; cin >> i && i; cout << ans[ i ] << endl );
}
