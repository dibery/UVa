#include<cstdio>
#include<cstring>
const long long MOD = 1000000009, N = 101;

void matmul( long long a[], long long b[][ N ], int size )
{
	long long ans[ N ] = { 0 };

	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			( ans[ i ] += a[ j ] * b[ j ][ i ] ) %= MOD;
	memcpy( a, ans, sizeof( ans ) );
}

void square( long long a[][ N ], int size )
{
	long long ans[ N ][ N ] = { { 0 } };

	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			for( int k = 0; k < size; ++k )
				( ans[ i ][ j ] += a[ i ][ k ] * a[ k ][ j ] ) %= MOD;
	memcpy( a, ans, sizeof( ans ) );
}

int calc( long long iv[], int size, long long term )
{
	long long m[ N ][ N ] = { { 0 } };
	
	for( int i = 1; i < size; ++i )
		m[ i ][ i - 1 ] = 1;
	for( int i = 0; i < size; ++i )
		m[ i ][ size - 1 ] = 1;
	for( long long i = 1ll; i <= term; i <<= 1 )
	{
		if( i & term )
			matmul( iv, m, size );
		square( m, size );
	}

	return *iv;
}

int main()
{
	for( long long k, n; scanf( "%lld %lld", &k, &n ) && k; )
	{
		long long fib[ N ] = { 1, 1 };

		for( int i = 2; i < k; ++i )
			fib[ i ] = fib[ i - 1 ] * 2 % MOD;
		printf( "%d\n", calc( fib, k, n ) );
	}
}
