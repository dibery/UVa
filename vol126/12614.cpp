#include<cstdio>

int main()
{
	int t, size, tmp, max;
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		max = -1;
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d", &tmp );
			if( max < tmp )
				max = tmp;
		}
		printf( "Case %d: %d\n", i, max );
	}

	return 0;
}
