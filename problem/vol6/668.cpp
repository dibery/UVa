#include<cstdio>

int main()
{
	int t, n;

	for( scanf( "%d", &t ); t--; )
	{
		int group[ 100 ] = { 0 }, size = 0, sum = 0;

		scanf( "%d", &n );
		for( int i = 2; sum + i <= n; ++i )
			group[ size++ ] = i, sum += i;
		while( sum < n )
			for( int i = 1; sum < n && i <= size; ++sum, ++i )
				++group[ size-i ];

		for( int i = 0; i < size; ++i )
			printf( "%d%c", group[ i ], i == size-1? '\n' : ' ' );
		if( t )
			puts( "" );
	}
}
