#include<bits/stdc++.h>
using namespace std;

int main()
{

	for( long long n; scanf( "%lld", &n ) == 1; )
	{
		int pos[ 20 ] = { 0 }, l;
		char s[ 21 ] = { 0 }, num[ 65 ] = { 0 };
		long long ans = -1;

		scanf( "%d", &l );
		for( int i = 0; i < l; ++i )
		{
			scanf( "%d", pos + i );
			s[ i ] = n & 1ll << pos[ i ]? '1' : '0';
			pos[ i ] = 60 - pos[ i ];
		}
		for( int i = 60; i >= 0; --i )
			num[ 60 - i ] = n & 1ll << i? '1' : '0';

		sort( s, s + l, greater<char>() );
		reverse( pos, pos + l );

		do
		{
			for( int i = 0; i < l; ++i )
				num[ pos[ i ] ] = s[ i ];
			long long x = strtoll( num, NULL, 2 );
			if( x % 7 == 0 )
				ans = x;
		}
		while( ans == -1 && prev_permutation( s, s + l ) );

		printf( "%lld\n", ans );
	}
}
