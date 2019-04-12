#include<bits/stdc++.h>
using namespace std;

const int N = 500001;
long long num[ N ], sum[ N ], values[ N ], target;
int t, len, uniq_len;

int main()
{
	for( scanf( "%d", &t ); t-- && scanf( "%d %lld", &len, &target ); )
	{
		for( int i = 1; i <= len; ++i )
		{
			scanf( "%lld", num + i );
			values[ i - 1 ] = sum[ i ] = sum[ i - 1 ] + num[ i ];
		}
		if( target <= 0 )
		{
			printf( "%d\n", *max_element( num + 1, num + len + 1 ) >= target? 1 : -1 );
			continue;
		}
		sort( values, values + len );
		uniq_len = unique( values, values + len ) - values;

		stack<int> *bit = new stack<int>[ uniq_len + 1 ];
		int ans = 1e9;

		for( int i = 1; i <= len; ++i )
			for( int pos = lower_bound( values, values + uniq_len, sum[ i ] ) - values + 1; 
					pos <= uniq_len; pos += pos & -pos )
				bit[ pos ].push( i );
		for( int i = len; i; --i )
			if( sum[ i ] >= target )
				ans = i;
		for( int i = len; i; --i )
			for( int search_pos = upper_bound( values, values + uniq_len, sum[ i ] - target ) - values;
					search_pos; search_pos -= search_pos & -search_pos )
			{
				while( !bit[ search_pos ].empty() && bit[ search_pos ].top() > i )
					bit[ search_pos ].pop();
				if( !bit[ search_pos ].empty() )
					ans = min( ans, i - bit[ search_pos ].top() );
			}
		printf( "%d\n", ans == 1e9? -1 : ans );
		delete[] bit;
	}
}
