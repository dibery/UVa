#include<cstdio>

int main()
{
	long long int n, slot[ 91 ] = { 1, 1, 2 };
	for( int i = 2; i <= 90; ++i )
		slot[ i ] = slot[ i-1 ] + slot[ i-2 ];
	while( scanf( "%lld", &n ) == 1 )
	{
		int index[ 90 ], size = 0;
		printf( "%lld\n", n );
		for( int i = 90; i && n; --i )
			if( slot[ i ] <= n )
				n -= slot[ i ], index[ ++size ] = i;
		for( int i = 1; i <= size; ++i )
			printf( "%d%c", index[ i ], i == size? '\n' : ' ' );
		for( int i = 1; i <= size; ++i )
			printf( "%lld%c", slot[ index[ i ] ], i == size? '\n' : ' ' );
		puts( "" );
	}
}
