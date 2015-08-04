#include<cstdio>
#include<algorithm>

int main()
{
	int t, size, val[ 20000 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		bool neg = true;
		scanf( "%d", &size );
		--size;
		for( int i = 0; i < size; ++i )
			scanf( "%d", val+i ), neg &= val[ i ] <= 0;
		if( neg )
			printf( "Route %d has no nice parts\n", n );
		else
		{
			int begin = 0, end = 0, M = 0, sum = 0, span = 0, tmp = 0;
			for( int i = 0; i < size; ++i )
			{
				sum += val[ i ];
				if( sum > M || sum == M && i - tmp > span )
					M = sum, end = i, begin = tmp, span = end - begin;
				else if( sum < 0 )
					sum = 0, tmp = i+1;
			}
			printf( "The nicest part of route %d is between stops %d and %d\n", n, begin+1, end+2 );
		}
	}
}
