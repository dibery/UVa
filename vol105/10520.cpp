#include<cstdio>
#include<cstring>
#include<algorithm>
long long int matrix[ 20 ][ 20 ] = { { 0 } };
int size, tmp;
bool vis[ 20 ][ 20 ] = { { false } };

long long int a( int i, int j )
{
	if( vis[ i ][ j ] )
		return matrix[ i ][ j ];
	vis[ i ][ j ] = true;
	if( i < j )
		for( int k = i; k < j; ++k )
			matrix[ i ][ j ] = std::max( matrix[ i ][ j ], a( i, k ) + a( k+1, j ) );
	else
	{
		long long int A = 0, B = 0;
		if( i != size )
			for( int k = i+1; k <= size; ++k )
				A = std::max( A, a( k, 1 ) + a( k, j ) );
		if( j )
			for( int k = 1; k < j; ++k )
				B = std::max( B, a( i, k ) + a( size, k ) );
		matrix[ i ][ j ] = A+B;
	}
	return matrix[ i ][ j ];
}

int main()
{
	while( scanf( "%d %d", &size, &tmp ) == 2 )
	{
		memset( matrix, 0, sizeof( matrix ) );
		memset( vis, false, sizeof( vis ) );
		vis[ size ][ 1 ] = true;
		matrix[ size ][ 1 ] = tmp;
		printf( "%lld\n", a( 1, size ) );
	}
}
