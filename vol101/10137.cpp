#include<cstdio>
#include<cstdlib>
#include<algorithm>

int main()
{
	int size, spend[ 1000 ], dollar, cent;

	while( scanf( "%d", &size ) && size )
	{
		int total = 0, ans = 0, up = 0, down = 0;
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d.%d", &dollar, &cent );
			total += spend[ i ] = dollar * 100 + cent;
		}
		if( total % size == 0 )
		{
			for( int i = 0; i < size; ++i )
				ans += abs( spend[ i ] - total / size );
			ans >>= 1;
		}
		else
		{
			for( int i = 0; i < size; ++i )
				if( spend[ i ] > total / size )
					up += spend[ i ] - total / size - 1;
				else
					down += total / size - spend[ i ];
			ans = std::max( up, down );
		}
		printf( "$%d.%02d\n", ans / 100, ans % 100 );
	}
}
