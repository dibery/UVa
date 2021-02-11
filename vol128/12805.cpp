#include<bits/stdc++.h>
using namespace std;

struct prime
{
	prime( int size ) : is_prime( size + 1, true )
	{
		is_prime[ 0 ] = is_prime[ 1 ] = false;
		for( int i = 4; i <= size; i += 2 )
			is_prime[ i ] = false;
		for( int i = 3; i * i <= size; i += 2 )
			if( is_prime[ i ] )
				for( int j = i * i; j <= size; j += i << 1 )
					is_prime[ j ] = false;
		for( int i = 2; i <= size; ++i )
			if( is_prime[ i ] )
				primes.push_back( i );
	}
	vector<bool> is_prime;
	vector<int> primes;
};

struct factorize // c++11 required
{
	factorize( int size ) : p( size ), div_prime( size + 1 )
	{
		for( int i = 2; i <= size; ++i )
			if( is_prime( i ) )
				div_prime[ i ] = i;
			else
				for( int j: p.primes )
					if( i % j == 0 )
					{
						div_prime[ i ] = j;
						break;
					}
	}
	vector<int>& primes() { return p.primes; }
	bool is_prime( int n ) { return p.is_prime[ n ]; }
	prime p;
	vector<int> div_prime;
};

int main()
{
	const int N = 100000;
	factorize f( N );
	bool plus[ N + 1 ] = { true, true, true };
	int q, n;

	for( int i = 3; i <= N; ++i )
		plus[ i ] = f.is_prime( i )? i % 4 == 3 : plus[ i / f.div_prime[ i ] ] ^ !plus[ f.div_prime[ i ] ];
	for( scanf( "%d", &n ); n-- && scanf( "%d", &q ); puts( plus[ q ]? "+" : "-" ) );
}
