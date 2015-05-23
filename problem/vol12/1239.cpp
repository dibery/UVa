#include<cstdio>
#include<cstring>

int calc( char *s, int diff, int mid )
{
	int a = -1, b = 0;

	for( int i = 0, d = diff; d >= 0 && mid - i >= 0 && s[ mid + i ]; ++i )
	{
		if( s[ mid + i ] != s[ mid - i ] )
			--d;
		if( d >= 0 )
			a += 2;
	}
	for( int i = 0, d = diff; d >= 0 && mid - i >= 0 && s[ mid + i + 1 ]; ++i )
	{
		if( s[ mid + i + 1 ] != s[ mid - i ] )
			--d;
		if( d >= 0 )
			b += 2;
	}
	return a > b? a : b;
}

int main()
{
	int t, k;

	for( scanf( "%d", &t ); t--; )
	{
		char s[ 1001 ] = { 0 };
		int ans = 0;

		scanf( "%s %d", s, &k );
		for( int i = 0; s[ i ]; ++i )
			ans = max( ans, calc( s, k, i );
		printf( "%d\n", ans );
	}
}
