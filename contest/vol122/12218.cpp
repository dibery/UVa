#include<bits/stdc++.h>
using namespace std;
const int N = 10000000;

bool notprime[ N ] = { true, true };
int primes[ 670000 ] = { 2 }, S = 1, cmp[ 670000 ][ 10 ] = { { 0, 0, 1 } };

int main()
{
	int t;
	char s[ 10 ];

	for( int i = 4; i < N; i += 2 )
		notprime[ i ] = true;
	for( int i = 3; i*i < N; i += 2 )
		if( !notprime[ i ] )
			for( int j = i*i; j < N; j += 2*i )
				notprime[ j ] = true;
	for( int i = 3; i < N; i += 2 )
		if( !notprime[ i ] )
		{
			sprintf( s, "%d", i );
			for( int j = 0; s[ j ]; ++j )
				++cmp[ S ][ s[ j ] - '0' ];
			primes[ S++ ] = i;
		}

	for( scanf( "%d", &t ); t--; )
	{
		int show[ 10 ] = { 0 }, prime = 0;

		scanf( "%s", s );
		for( int i = 0; s[ i ]; ++i )
			++show[ s[ i ] - '0' ];
		for( int i = 0; i < S; ++i )
		{
			bool ok = true;
			for( int j = 0; j < 10; ++j )
				if( show[ j ] < cmp[ i ][ j ] )
					ok = false;
			prime += ok;
		}
		printf( "%d\n", prime );
	}
}
