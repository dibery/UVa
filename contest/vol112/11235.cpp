#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[ 100000 ], qnt, query, from, to, begin[ 100000 ], times[ 100000 ], end[ 100000 ], grp[ 100000 ], pow2[ 20 ], rmq[ 100000 ][ 20 ];
int log2( int n )
{
	for( int i = 0; ; ++i )
		if( pow2[ i ] > n )
			return i-1;
		else if( pow2[ i ] == n )
			return i;
}

int main()
{
	for( int i = 0; i < 20; ++i )
		pow2[ i ] = 1 << i;
	while( scanf( "%d %d", &qnt, &query ) == 2 )
	{
		int tag = 0;
		memset( grp, 0, sizeof( grp ) );
		memset( begin, 0, sizeof( begin ) );
		memset( times, 0, sizeof( times ) );
		memset( end, 0, sizeof( end ) );
		memset( rmq, 0, sizeof( rmq ) );

		for( int i = 0; i < qnt; ++i )
			scanf( "%d", num+i );

		for( int i = 0; i <= qnt; ++i )
			if( !i || num[ i ] != num[ i-1 ] || i == qnt )
			{
				if( i )
				{
					end[ tag ] = i;
					times[ tag ] = end[ tag ] - begin[ tag ];
					++tag;
					if( i == qnt )
						break;
				}
				grp[ i ] = tag;
				begin[ tag ] = i;
			}
			else
				grp[ i ] = tag;
		for( int i = 0; i < tag; ++i )
			*rmq[ i ] = times[ i ];
		for( int exp = 1; pow2[ exp ] <= tag; ++exp )
			for( int i = 0; i + pow2[ exp ] <= tag; ++i )
				rmq[ i ][ exp ] = max( rmq[ i ][ exp-1 ], rmq[ i + pow2[ exp-1 ] ][ exp-1 ] );

		for( int i = 0; i < query; ++i )
		{
			scanf( "%d %d", &from, &to );
			--from, --to;
			if( grp[ from ] == grp[ to ] )
				printf( "%d\n", to-from+1 );
			else if( grp[ from ]+1 == grp[ to ] )
				printf( "%d\n", max( end[ grp[ from ] ] - from, to - begin[ grp[ to ] ] + 1 ) );
			else
				printf( "%d\n", max( max( end[ grp[ from ] ] - from, to - begin[ grp[ to ] ] + 1 ), max( rmq[ grp[ from ]+1 ][ log2( grp[ to ] - grp[ from ] - 1 ) ], rmq[ grp[ to ]-pow2[ log2( grp[ to ] - grp[ from ] - 1 ) ] ][ log2( grp[ to ] - grp[ from ] - 1 ) ] ) ) );
		}
	}

	return 0;
}
