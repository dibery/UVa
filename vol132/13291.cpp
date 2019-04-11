#include<cstdio>

int main()
{
	for( int n; scanf( "%d", &n ) == 1; )
	{
		long long len[ 3 ] = { 0 }, area[ 3 ] = { 0 };

		for( int i = 0, l; i < n && scanf( "%d", &l ); ++i )
			len[ i % 3 ] += l;
		for( int i = 0, l; i < n && scanf( "%d", &l ); ++i )
			for( int j = 0; j < 3; ++j )
				area[ ( i + j ) % 3 ] += l * len[ j ];
		printf( "%lld %lld %lld\n", area[ 1 ], area[ 2 ], area[ 0 ] );
	}
}
