#include<cstdio>

bool ok( char s[], int sq )
{
	char str[ 5 ];
	int diff = 0;

	sprintf( str, "%d", sq );
	for( int i = 0; i < 4; ++i )
		diff += str[ i ] != s[ i ];
	return diff == 1;
}

int main()
{
	int sqr[ 68 ], t;
	char s[ 5 ];

	for( int i = 32; i < 100; ++i )
		sqr[ i - 32 ] = i * i;

	scanf( "%d\n", &t );
	for( int n = 1; n <= t; ++n )
	{
		int ans = 0;
		gets( s );
		for( int i = 0; i < 68; ++i )
			ans += ok( s, sqr[ i ] );
		printf( "Case %d: %d\n", n, ans );
	}
}
