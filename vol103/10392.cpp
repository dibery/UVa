#include<cstdio>

int prime[ 80000 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	long long int n;
	for( int i = 3; i < 1000000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	while( scanf( "%lld", &n ) && n >= 0 )
	{
		if( n == 0 )
			continue;
		for( int i = 0; i < size && n > 1; ++i )
			while( n % prime[ i ] == 0 )
				n /= prime[ i ], printf( "%d\n", prime[ i ] );
		if( n != 1 )
			printf( "    %lld\n", n );
		puts( "" );
	}
}
