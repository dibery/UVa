#include<cstdio>
int gcd( int a, int b ) { return a % b == 0? b : gcd( b, a%b ); }

int main()
{
	int t, m, n;
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d %d", &m, &n );
		printf( "Case %d: %d\n", i, ( m+n ) / gcd( m, n ) );
	}
}
