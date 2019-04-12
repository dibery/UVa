#include<bits/stdc++.h>
using namespace std;
const int NPOS = INT_MAX;

struct tree
{
	long long low, mid, high;
	set<int> indice;
	tree *left, *right;
	tree( long long l, long long h )
	{
		low = l;
		high = h;
		mid = ( high + low ) / 2;
		if( low < 0 && high - low == 1 )
			--mid;
		left = right = NULL;
	}
	~tree()
	{
		if( left )
			delete left;
		if( right )
			delete right;
	}
	void insert( int val, int index )
	{
		//printf( "Insert to tree with high = %lld, mid = %lld, low = %lld\n", high, mid, low );
    indice.insert( index );
		if( low == high )
			return;
		if( val > mid )
			if( right )
				right->insert( val, index );
			else
				( right = new tree( mid + 1, high ) )->insert( val, index );
		else if( left )
			left->insert( val, index );
		else
			( left = new tree( low, mid ) )->insert( val, index );
	}
	int search( long long val, int index )
	{
		//printf( "Enter layer: high = %lld, mid = %lld, low = %lld\n", high, mid, low );
		if( val <= low )
		{
			auto i = indice.lower_bound( index );
			return i != indice.end()? *i : NPOS;
		}
		else if( val > mid )
		{
			//printf( "Return %d\n", right? right->search( val, index ) : NPOS );
			return right? right->search( val, index ) : NPOS;
		}
		else
		{
			//printf( "Return %d\n", min( right? right->search( val, index ) : NPOS, left? left->search( val, index ) : NPOS ) );
			return min( right? right->search( val, index ) : NPOS, left? left->search( val, index ) : NPOS );
		}
	}
};

int main()
{
	int t, size, ans;
	long long target, *n = new long long[ 500001 ], *sum = new long long[ 500001 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %lld", &size, &target ); )
	{
		ans = NPOS;
		*sum = 0;
		for( int i = 0; i < size; ++i )
			scanf( "%lld", n + i ), sum[ i ] = n[ i ];
		for( int i = 1; i < size; ++i )
			sum[ i ] += sum[ i - 1 ];
		tree t( *min_element( sum, sum + size ), *max_element( sum, sum + size ) );
		for( long long i = 0, sum = *n; i < size; sum += n[ ++i ] )
			t.insert( sum, i );
		for( int i = 0; i < size; ++i )
		{
			int pos = t.search( target + sum[ i ] - n[ i ], i );
			//printf( "\nGet %d at position %d\n\n", pos, i );
			if( pos != NPOS )
				ans = min( ans, pos - i + 1 );
		}
		printf( "%d\n", ans == NPOS? -1 : ans );
	}
}
