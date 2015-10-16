#include<cstdio>

int main()
{
	for( int size, x[ 200000 ], y[ 200000 ]; scanf( "%d", &size ) && size; )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d %d", x + i, y + i );
		int cx = x[ size / 2 ], cy = y[ size / 2 ], stan = 0, ollie = 0;
		for( int i = 0; i < size; ++i )
			if( x[ i ] > cx && y[ i ] > cy || x[ i ] < cx && y[ i ] < cy )
				++stan;
			else if( x[ i ] < cx && y[ i ] > cy || x[ i ] > cx && y[ i ] < cy )
				++ollie;
		printf( "%d %d\n", stan, ollie );
	}
}
