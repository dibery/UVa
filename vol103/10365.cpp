#include<cstdio>
#include<algorithm>

int main()
{
	int t, n;

	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); )
	{
		int ans = 1e9;
		for( int i = 1; i <= 10; ++i )
			for( int j = i; i * j * j <= 1000; ++j )
				if( n % ( i * j ) == 0 )
				{
					int k = n / i / j;
					ans = std::min( ans, 2 * ( i * j + i * k + j * k ) );
				}
		printf( "%d\n", ans );
	}
}
