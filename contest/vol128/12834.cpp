#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size, n, minus, t = 0;
	scanf( "%*s" );

	while( scanf( "%d %d", &size, &minus ) == 2 )
	{
		int* profit = (int*) calloc( size, sizeof( int ) );
		long long int all = 0;
		for( int i = 0; i < size; ++i )
			scanf( "%d", &n ), profit[ i ] -= n;
		for( int i = 0; i < size; ++i )
			scanf( "%d", &n ), profit[ i ] += n;
		sort( profit, profit+size, greater<int>() );
		for( int i = size-minus; i < size; ++i )
			if( profit[ i ] < 0 )
				profit[ i ] = 0;
		for( int i = 0; i < size; ++i )
			all += profit[ i ];
		if( all <= 0 )
			printf( "Case %d: No Profit\n", ++t );
		else
			printf( "Case %d: %lld\n", ++t, all );
		free( profit );
	}
}
