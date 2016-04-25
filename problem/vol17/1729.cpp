#include<cstdio>
#include<algorithm>

int main()
{
	int t;
	char s[ 100001 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%s", s );
		int times[ 26 ] = { 0 };
		for( int i = 0; s[ i ]; ++i )
			++times[ s[ i ] - 'a' ];
		printf( "Case %d: %d\n", n, *std::min_element( times, times + 26 ) );
	}
}
