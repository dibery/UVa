#include<bits/stdc++.h>
#define N 500001
using namespace std;
int prime[ 50000 ] = { 2 }, size = 1, sopf[ N ], lsopf[ N ];

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i < N; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i, sopf[ i ] = i;

	for( int i = 2; i < N; ++i )
		for( int j = 0; !sopf[ i ]; ++j )
			if( i % prime[ j ] == 0 )
				sopf[ i ] = prime[ j ] + sopf[ i / prime[ j ] ];
	for( int i = 2; i < N; ++i )
		lsopf[ i ] = i == sopf[ i ]? 1 : lsopf[ sopf[ i ] ] + 1;

	int t, low, high;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &low, &high );
		if( low > high )
			swap( low, high );
		printf( "Case #%d:\n%d\n", n, *max_element( lsopf + low, lsopf + high + 1 ) );
	}
}
