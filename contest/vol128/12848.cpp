#include<cstdio>

inline int gcd( int a, int b ) { return a % b? gcd( b, a % b ) : b; }

int main()
{
	int t, h1, s, h2;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d", &h1, &s, &h2 );
		s = s * --h2;
		--h1;
		if( s % h1 )
			if( s < h1 )
				printf( "Case %d: %d/%d\n", n, s / gcd( s, h1 ), h1 / gcd( s, h1 ) );
			else
				printf( "Case %d: %d %d/%d\n", n, s / h1, s % h1 / gcd( s, h1 ), h1 / gcd( s, h1 ) );
		else
			printf( "Case %d: %d\n", n, s / h1 );
	}
}
