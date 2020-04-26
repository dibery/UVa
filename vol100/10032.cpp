#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, len, weight[ 100 ];
	bitset<23000> *dp = new bitset<23000>[ 51 ];
	dp->set( 0 );

	for( scanf( "%d", &t ); t-- && scanf( "%d", &len ); printf( t? "\n" : "" ) )
	{
		for( int i = 0; i < len; ++i )
			scanf( "%d", weight + i );
		for( int i = 1; i < 51; ++i )
			dp[ i ].reset();
		for( int i = 0; i < len; dp[ 1 ].set( weight[ i++ ] ) )
			for( int j = len / 2; j; --j )
				dp[ j ] |= dp[ j - 1 ] << weight[ i ];
		int sum = accumulate( weight, weight + len, 0 ), diff = INT_MAX, less, more;
		for( int i = dp->size() - 1; i >= 0; --i )
			if( dp[ len / 2 ].test( i ) && diff > abs( i - sum + i ) )
				less = i, more = sum - less, diff = abs( i - sum + i );
		printf( "%d %d\n", min( less, more ), max( less, more ) );
	}
}
