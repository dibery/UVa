#include<cstdio>
#define M 10000000000007ll

int main()
{
	int t, size, low, high;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d", &size, &low, &high );
		long long ans = 0, tmp = 1;
		for( int i = 1, S = size * size; i <= high; ++i )
		{
			tmp = tmp * S-- % M;
			if( i >= low )
				ans = ( ans + tmp ) % M;
		}
		printf( "Case %d: %lld\n", n, ans );
	}
}
