#include<cstdio>
int opt( int n )
{
	int back = 1;
	while( n )
		back += n & 1, n >>= 1;
	return back;
}
int pess( int n )
{
	int back = 0;
	while( n && !( n & 1 ) )
		n >>= 1, ++back;
	return ( 1 << back ) - 1;
}

int main()
{
	int t, match, team;
	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%d %d", &match, &team );
		printf( "%d %d\n", opt( team ), team? ( 1 << match ) - pess( team ) : 1 );
	}

	return 0;
}
