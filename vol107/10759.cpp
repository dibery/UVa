#include<cstdio>

long long gcd( long long a, long long b ) { return a % b? gcd( b, a % b ) : b; }

int main()
{
	long long ways[ 25 ][ 145 ] = { { 1 } }, pow[ 25 ] = { 1 };

	for( int i = 1; i < 25; ++i )
		pow[ i ] = pow[ i - 1 ] * 6;
	for( int i = 1; i < 25; ++i )
		for( int j = i; j < 145; ++j )
			for( int k = 1; k <= 6 && k <= j; ++k )
				ways[ i ][ j ] += ways[ i - 1 ][ j - k ];
	
	for( int n, x; scanf( "%d %d", &n, &x ) && n; )
	{
		long long ok = 0, all = pow[ n ], f;
		for( int i = x; i <= n * 6; ++i )
			ok += ways[ n ][ i ];
		f = gcd( ok, all );
		if( !ok )
			puts( "0" );
		else if( ok == all )
			puts( "1" );
		else
			printf( "%lld/%lld\n", ok / f, all / f );
	}
}
