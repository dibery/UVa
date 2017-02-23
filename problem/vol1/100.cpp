#include<bits/stdc++.h>
int calc( int start );

int main()
{
	for( int i, j, M = 0; scanf( "%d %d", &i, &j ) != EOF; M = 0 )
	{
		printf( "%d %d", i, j );
		if( i > j )
			std::swap( i, j );
		for( int x = i; x <= j; x++ )
			M = std::max( M, calc( x ) );
		printf( " %d\n", M + 1 );
	}
}

int calc( int start )
{
	int length = 0;
	for( ; start != 1; ++length )
		start = start % 2? 3 * start + 1 : start / 2;
	return length;
}
