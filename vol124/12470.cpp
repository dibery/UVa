#include<cstdio>
#include<cstring>
const int MOD = 1000000009;

struct matrix	// 3*3
{
	long long val[ 3 ][ 3 ];
	matrix operator*( const matrix& m )
	{
		matrix result;
		for( int i = 0; i < 3; ++i )
			for( int j = 0; j < 3; ++j )
			{
				result.val[ i ][ j ] = 0;
				for( int k = 0; k < 3; ++k )
					result.val[ i ][ j ] += val[ i ][ k ] * m.val[ k ][ j ];
				result.val[ i ][ j ] %= MOD;
			}
		return result;
	}
	void operator=( const matrix& m )
	{
		for( int i = 0; i < 9; ++i )
			val[ i / 3 ][ i % 3 ] = m.val[ i / 3 ][ i % 3 ];
	}
	matrix( int n[] )
	{
		for( int i = 0; i < 9; ++i )
			val[ i / 3 ][ i % 3 ] = n[ i ];
	}
	matrix() { memset( val, 0, sizeof( val ) ); }
};

int main()
{
	int init[] = { 0, 1, 0, 0, 0, 1, 1, 1, 1 }, base[] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	matrix fib[ 64 ];

	*fib = matrix( init );
	for( int i = 1; i < 64; ++i )
		fib[ i ] = fib[ i - 1 ] * fib[ i - 1 ];

	for( long long n; scanf( "%lld", &n ) && n--; )
	{
		matrix power( base );
		for( int i = 0; i < 63; ++i )
			if( n & 1ll << i )
				power = power * fib[ i ];
		printf( "%lld\n", ( power.val[ 0 ][ 1 ] + power.val[ 0 ][ 2 ] * 2 ) % MOD );
	}
}
