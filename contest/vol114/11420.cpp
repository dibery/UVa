#include<cstdio>

int main()
{
	int total, lock, dp[ 66 ][ 66 ] = { { 1 } };
	for( int i = 1; i <= 65; ++i )
		for( int j = 0; j <= i; ++j )
				for( int k = 1; k <= i; ++k )
					dp[ i ][ j ] += dp[ i - k ][ j - ( k == 1 ) ];

	while( scanf( "%d %d", &total, &lock ) && total > 0 && lock >= 0 )
		printf( "%d\n", dp[ total ][ lock ] );
}
