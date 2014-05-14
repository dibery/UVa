#include<cstdio>
int gcd[ 101 ][ 101 ];
int GCD( int a, int b ) { return a % b? GCD( b, a % b ) : b; }
void bt( int *num, int index, int now, int left, int part )
{
	if( left == now && part == 1 )
	{
		for( int i = 0; i < index; ++i )
			if( gcd[ num[ i ] ][ now ] != 1 )
				return;
		for( int i = 0; num[ i ]; ++i )
			printf( "%d ", num[ i ] );
		printf( "%d\n", now );
		return;
	}
	if( left <= 0 || part <= 0 )
		return;
	for( int i = 0; i < index; ++i )
		if( gcd[ num[ i ] ][ now ] != 1 )
			return;
	num[ index ] = now;
	for( int i = now; i <= left; ++i )
		bt( num, index+1, i, left - now, part-1 );
	num[ index ] = 0;
}

int main()
{
	int t, total, part;
	scanf( "%d", &t );
	for( int i = 1; i <= 100; ++i )
		for( int j = i; j <= 100; ++j )
			gcd[ i ][ j ] = gcd[ j ][ i ] = GCD( i , j );

	for( int n = 1; n <= t; ++n )
	{
		int num[ 30 ] = { 0 };
		scanf( "%d %d", &total, &part );
		printf( "Case %d:\n", n );
		for( int i = 1; i <= total; ++i )
			bt( num, 0, i, total, part );
	}
}
