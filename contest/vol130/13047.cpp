#include<cstdio>

int max( int a, int b ) { return a < b? b : a; }

int count( char* s, int step )
{
	char* p = s + step;
	for( char c = *p; *p == c; p += step );
	return max( s - p, p - s );
}

int main()
{
	int t;
	char s[ 52 ] = { 0 };

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int ans = -1;

		scanf( "%s", s + 1 );
		for( int i = 1; s[ i ]; ++i )
			if( s[ i ] == '<' )
				if( s[ i + 1 ] == '-' || s[ i + 1 ] == '=' )
					ans = max( ans, count( s + i, 1 ) );
				else
					ans = max( ans, 1 );
			else if( s[ i ] == '>' )
				if( s[ i - 1 ] == '-' || s[ i - 1 ] == '=' )
					ans = max( ans, count( s + i, -1 ) );
				else
					ans = max( ans, 1 );

		printf( "Case %d: %d\n", n, ans );
	}
}
