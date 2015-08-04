#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
	int t, mod[ 100001 ] = { 1 };

	for( int i = 1; i <= 100000; ++i )
		mod[ i ] = mod[ i-1 ] * 2 % MOD;
	scanf( "%d\n", &t );

	for( int n = 1; n <= t; ++n )
	{
		char s[ 100001 ] = { 0 }, trans[ 100001 ] = { 0 };
		int len = strlen( gets( s ) ), size = 0, ans = 0;
		char *l = s + ( ( len-1 ) / 2 ), *r = s + ( len / 2 );

		if( l == r )
			trans[ size++ ] = *l--, ++r;
		for( ; *r; size += 2 )
			trans[ size ] = max( *l, *r ), trans[ size+1 ] = min( *l--, *r++ );

		reverse( trans, trans+len );
		for( int i = 0; trans[ i ]; ++i )
			ans = ( ans + ( trans[ i ] - '0' ) * mod[ i ] ) % MOD;
		printf( "Case #%d: %d\n", n, ans );
	}
}
