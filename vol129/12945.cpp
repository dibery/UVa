#include<cstdio>
#include<cmath>

int main()
{
	for( int size, x[ 100 ], y[ 100 ], w[ 100 ]; scanf( "%d", &size ) == 1; )
	{
		double avex = 0, avey = 0, all = 0, cost = 0;

		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d %d", x+i, y+i, w+i );
			avex += x[ i ] * w[ i ];
			avey += y[ i ] * w[ i ];
			all += w[ i ];
		}
		avex /= all;
		avey /= all;

		for( int i = 0; i < size; ++i )
			cost += ( ( avex - x[ i ] ) * ( avex - x[ i ] ) + ( avey - y[ i ] ) * ( avey - y[ i ] ) ) * w[ i ];
		printf( "%.3f\n", cost );
	}
}
