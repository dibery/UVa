#include<cstdio>

int main()
{
	int n, w[ 1 << 15 ];

	while( scanf( "%d", &n ) == 1 )
	{
		int M = 0;
		for( int i = 0; i < 1<<n; ++i )
			scanf( "%d", w+i );
		for( int i = 0; i < 1<<n; ++i )
			for( int j = 1; j < 1<<n; j <<= 1 )
			{
				int S = 0;
				for( int k = 0; k < n; ++k )
					S += w[ i ^ 1<<k ] + w[ i^j ^ 1<<k ];
				M = M < S? S : M;
			}
		printf( "%d\n", M );
	}
}
