#include<cstdio>

int main()
{
	int t, egg, quant, cap;
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d %d %d", &egg, &quant, &cap );
		int *weight = new int[ egg ], ans = 0, has = 0;

		for( int a = 0; a < egg; ++a )
			scanf( "%d", weight+a );
		for( ; ans < quant && ans < egg; ++ans )
			if( has + weight[ ans ] <= cap )
				has += weight[ ans ];
			else
				break;
		printf( "Case %d: %d\n", i, ans );
	}

	return 0;
}
