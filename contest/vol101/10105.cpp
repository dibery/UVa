#include<cstdio>

int main()
{
	int fact[ 13 ] = { 1 }, f, n;
	for( int i = 1; i < 13; ++i )
		fact[ i ] = fact[ i-1 ] * i;

	while( scanf( "%d %d", &f, &n ) == 2 )
	{
		int ans = fact[ f ];
		for( int i = 0; i < n; ++i )
			scanf( "%d", &f ), ans /= fact[ f ];
		printf( "%d\n", ans );
	}
}
