#include<bits/stdc++.h>
using namespace std;

const int N = 1000000, S = 78498;
bool notprime[ N + 1 ] = { true, true };
int primes[ S ] = { 2 }, size = 1, Pow[ S ][ 20 ], lp[ S ], T, in;

int main()
{
	freopen( ".test", "r", stdin );
	for( int i = 4; i <= N; i += 2 )
		notprime[ i ] = true;
	for( int i = 3; i * i < N; i += 2 )
		if( !notprime[ i ] )
			for( int j = i * i; j < N; j += i + i )
				notprime[ j ] = true;
	for( int i = 3; i < N; i += 2 )
		if( !notprime[ i ] )
			primes[ size++ ] = i;
	for( int i = 0; i < S; ++i )
		for( long long j = *Pow[ i ] = lp[ i ] = 1; j * primes[ i ] <= N; )
			Pow[ i ][ lp[ i ]++ ] = j *= primes[ i ];

	scanf( "%d", &T );
	for( int t = 1; t <= T && scanf( "%d", &in ); ++t )
	{
		int up[ S ] = { 0 };

		for( int i = 0; i < S; ++i )
			up[ i ] += primes[ i ];
		/*
			for( int j = 1; j < lp[ i ] && Pow[ i ][ j ] <= in; ++j )
				up[ i ] += in / Pow[ i ][ j ];
				*/
		size = up[ 0 ];
	}
	cout << size;
	return 0;
}
