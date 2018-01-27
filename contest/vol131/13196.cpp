#include<cstdio>
#include<cstring>

const int N = 5000001, coef[ 3 ] = { 6, 18, 36 };
int sol[ 3 ][ N ];

int query( int n, int layer = 2 )
{
	if( sol[ layer ][ n ] != -1 )
		return sol[ layer ][ n ];

	int ans = 0;
	for( int i = 0; coef[ layer ] * i * i <= n; ++i )
		ans += query( n - coef[ layer ] * i * i, layer - 1 );
	return sol[ layer ][ n ] = ans;
}

int main()
{
	memset( sol, -1, sizeof( sol ) );
	for( int i = 0; i < N; ++i )
		sol[ 0 ][ i ] = 0;
	for( int i = 0; 6 * i * i < N; ++i )
		sol[ 0 ][ 6 * i * i ] = 1;
	for( int n; scanf( "%d", &n ) == 1; )
		printf( "%d\n", query( 5 * n ) );
}
