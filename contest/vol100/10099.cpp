#include<bits/stdc++.h>
using namespace std;

int main()
{
	int city, route, t = 0, from, to, all, cap;
	
	while( scanf( "%d %d", &city, &route ) && city + route )
	{
		int adj[ 100 ][ 100 ] = { 0 }, Cap[ 100 ] = { 0 };
		bool vis[ 100 ] = { false };
		priority_queue<int> tmp;

		while( route-- )
		{
			scanf( "%d %d %d", &from, &to, &cap );
			--from, --to;
			adj[ from ][ to ] = adj[ to ][ from ] = cap-1;
		}
		scanf( "%d %d %d", &from, &to, &all );
		--from, --to;
		
		vis[ from ] = true;
		for( int i = 0; i < city; ++i )
			if( adj[ from ][ i ] )
				Cap[ i ] = adj[ from ][ i ], tmp.push( adj[ from ][ i ]*100 + i );
		while( !tmp.empty() )
		{
			int self = tmp.top() % 100;
			if( vis[ self ] )
			{
				tmp.pop();
				continue;
			}
			vis[ self ] = true;
			Cap[ self ] = tmp.top() / 100;
			for( int i = 0; i < city; ++i )
				if( !vis[ i ] && adj[ self ][ i ] )
					tmp.push( min( adj[ self ][ i ]*100, Cap[ self ]*100 ) + i );
		}
		printf( "Scenario #%d\nMinimum Number of Trips = %d\n\n", ++t, (all+Cap[to]-1)/Cap[to] );
	}
}
