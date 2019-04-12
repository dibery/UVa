#include<cstdio>
int sod( int n )
{
	int ans = 0;
	while( n )
		ans += n % 10, n /= 10;
	return ans;
}

int main()
{
	int t, mono[ 8 ], bi[ 8 ];
	char n[ 21 ];

	for( scanf( "%d", &t ); t--; )
	{
		int m = 0, b = 0;

		scanf( "%s %s %s %s", n, n+4, n+8, n+12 );
		for( int i = 0; i < 16; ++i )
			if( i % 2 == 0 )
				bi[ i >> 1 ] = n[ i ] - '0' << 1;
			else
				mono[ i >> 1 ] = n[ i ] - '0';
		for( int i = 0; i < 8; ++i )
			m += sod( mono[ i ] ), b += sod( bi[ i ] );
		puts( ( m + b ) % 10? "Invalid" : "Valid" );
	}
}
