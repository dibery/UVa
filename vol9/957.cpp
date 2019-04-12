#include<cstdio>

int main()
{
	for( int span, pope, year[ 100001 ]; scanf( "%d %d", &span, &pope ) == 2; )
	{
		for( int i = 0; i < pope; ++i )
			scanf( "%d", year + i );
		year[ pope ] = 1e9;

		int ans = 0, begin, end, next;

		for( int i = 0; i < pope; ++i )
		{
			for( next = i; year[ next ] - year[ i ] < span; ++next );
			if( ans < next - i )
			{
				ans = next - i;
				begin = year[ i ];
				end = year[ next - 1 ];
			}
		}

		printf( "%d %d %d\n", ans, begin, end );
	}
}
