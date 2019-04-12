#include<cstdio>
#include<cstring>

int main()
{
	int a, b, n;

	while( scanf( "%d %d", &a, &b ) != EOF && a )
	{
		int A[ 10 ] = { 0 }, B[ 10 ] = { 0 }; //factors

		for( int i = 0; i < a; ++i )
		{
			scanf( "%d", &n );
			for( int j = 2; j <= n; ++j )  //n!, 2*3*4...*n
				for( int k = 2, tmp = j; k <= n; ++k )
					while( tmp % k == 0 )
						tmp /= k, ++A[ k ];
		}
		for( int i = 0; i < b; ++i )
		{
			scanf( "%d", &n );
			for( int j = 2; j <= n; ++j )
				for( int k = 2, tmp = j; k <= n; ++k )
					while( tmp % k == 0 )
						tmp /= k, ++B[ k ];
		}

		puts( memcmp( A, B, sizeof( A ) )? "NO" : "YES" );
	}
}
