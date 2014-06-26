#include<cstdio>

int main()
{
	int total, lock;
	long long int dp[ 66 ][ 66 ] = { { 1 }, { 1 } };
	for( int i = 2; i <= 65; ++i )
	{
		for( int j = 2; j <= i; ++j )
			dp[ i ][ 0 ] += dp[ i-j ][ 0 ];
		++dp[ i ][ 0 ];
	}
	for( int i = 1; i <= 65; ++i )
		for( int j = 1; j <= i; ++j )
			for( int k = 1; k <= i; ++k )
				dp[ i ][ j ] += dp[ i - k ][ j - ( k == 1 ) ];

	while( scanf( "%d %d", &total, &lock ) && total > 0 && lock >= 0 )
		printf( "%lld\n", dp[ total ][ lock ] );
}
