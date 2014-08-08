#include<cstdio>
#include<cstring>

int prime[ 170 ] = { 2 }, size = 1, single[ 1000001 ], ans[ 1000001 ];

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	int n;

	for( int i = 3; i < 1000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;
	for( int i = 2; i <= 1000000; ++i )
	{
		int tmp = i;
		for( int j = 0; j < size && tmp > 1; ++j )
			while( tmp % prime[ j ] == 0 )
				tmp /= prime[ j ], ++single[ i ];
		single[ i ] += tmp > 1;
	}
	for( int i = 2; i <= 1000000; ++i )
		ans[ i ] = ans[ i-1 ] + single[ i ];

	while( scanf( "%d", &n ) == 1 )
		printf( "%d\n", ans[ n ] );
}
