#include<cstdio>

char get( int N, int x, int y )
{
	if( x >= N )
		x = N - 1 - ( x - N + 1 );
	if( y >= N )
		y = N - 1 - ( y - N + 1 );
	if( x + y < N-1 )
		return '.';
	return ( ( 2 * N - 2 ) - ( x + y ) ) % 26 + 'a';
}

int main()
{
	for( int N, r1, c1, r2, c2, t = 0; scanf( "%d %d %d %d %d", &N, &r1, &c1, &r2, &c2 ) && N; )
	{
		printf( "Case %d:\n", ++t );
		for( int i = r1; i <= r2; ++i, puts( "" ) )
			for( int j = c1; j <= c2; ++j )
				putchar( get( N, i % ( 2*N-1 ), j % ( 2*N-1 ) ) );
	}
}
