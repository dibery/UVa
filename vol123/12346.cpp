#include<cstdio>
#include<climits>

int allf[ 1 << 20 ], allc[ 1 << 20 ];

int main()
{
	int gate, F[ 20 ], C[ 20 ], t, need, time;

	scanf( "%d", &gate );
	for( int i = 0; i < gate; ++i )
	{
		scanf( "%d %d", F + i, C + i );
		allf[ 1 << i ] = F[ i ];
		allc[ 1 << i ] = C[ i ];
	}
	for( int i = 1; i < 1 << gate; ++i )
	{
		allf[ i ] = allf[ i & -i ] + allf[ i ^ i & -i ];
		allc[ i ] = allc[ i & -i ] + allc[ i ^ i & -i ];
	}

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &need, &time );
		int cost = INT_MAX;

		for( int i = 1; i < 1 << gate; ++i )
			if( allf[ i ] * time >= need && allc[ i ] < cost )
				cost = allc[ i ];

		if( cost == INT_MAX )
			printf( "Case %d: IMPOSSIBLE\n", n );
		else
			printf( "Case %d: %d\n", n, cost );
	}
}
