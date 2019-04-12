#include<cstdio>
long long int gcd( long long int a, long long int b ) { return a % b? gcd( b, a % b ) : b; }

int main()
{
	int t, size, num[ 8 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		long long int up = 1, down = 0;
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%d", num+i ), up *= num[ i ];
		for( int i = 0; i < size; ++i )
			down += up / num[ i ];
		up *= size;
		long long int factor = gcd( up, down );
		printf( "Case %d: %lld/%lld\n", n, up / factor, down / factor );
	}
}
