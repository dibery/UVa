#include<cstdio>
#include<algorithm>

int main()
{
	scanf( "%*d" );
	for( int n, cap, w[ 100001 ], ans, sum; scanf( "%d %d", &n, &cap ) == 2; )
	{
		for( int i = 0; i < n; ++i )
			scanf( "%d", w + i );
		std::sort( w, w + n );
		for( ans = sum = 0; sum + w[ ans ] <= cap && ans < n; ++ans )
			sum += w[ ans ];
		printf( "%d\n", ans );
	}
}
