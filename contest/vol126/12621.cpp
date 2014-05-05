#include<cstdio>
#include<algorithm>

int main()
{
	int t, budget, item[ 1000 ] = { 0 }, qnt;

	for( scanf( "%d", &t ); t--; )
	{
		int all = 0, ans = 0;
		scanf( "%d %d", &budget, &qnt );
		budget /= 10;
		for( int i = 1; i <= qnt; ++i )
		{
			scanf( "%d", item + i );
			all += item[ i ] /= 10;
		}
		if( all < budget )
		{
			puts( "NO SOLUTION" );
			continue;
		}
		if( all == budget )
		{
			printf( "%d0\n", budget );
			continue;
		}
		int** dp = new int*[ qnt+1 ];
		for( int i = 0; i <= qnt; ++i )
			dp[ i ] = new int[ all+1 ];
		for( int i = 0; i <= all; ++i )
			dp[ 0 ][ i ] = 0;
		for( int i = 0; i <= qnt; ++i )
			dp[ i ][ 0 ] = 0;
		for( int j = 1; j <= all && !ans; ++j )
			for( int i = 1; i <= qnt && !ans; ++i )
			{
				if( item[ i ] > j )
					dp[ i ][ j ] = dp[ i-1 ][ j ];
				else
					dp[ i ][ j ] = std::max( dp[ i-1 ][ j ], dp[ i-1 ][ j - item[ i ] ] + item[ i ] );
				if( dp[ i ][ j ] >= budget )
					ans = dp[ i ][ j ];
			}
		printf( "%d0\n", ans );
	}
	return 0;
}
