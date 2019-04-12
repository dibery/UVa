#include<cstdio>

int joseph( int man, int count ) { return man == 1? 0 : ( joseph( man-1, count ) + count ) % man; }

int main()
{
	int t, man, count;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &man, &count );
		printf( "Case %d: %d\n", n, joseph( man, count ) + 1 );
	}
}
