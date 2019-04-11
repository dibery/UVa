#include<cstdio>
#define N 1048576
int n, size = 0, composite[ 1000000 ];
bool cp[ N+1 ], prime[ N+1 ];

bool isp( int n )
{
	for( int i = 2; i*i <= n; ++i )
		if( n % i == 0 )
			return false;
	return true;
}

int main()
{
	prime[ 1 ] = true;
	for( int i = 2; i <= N; ++i )
		if( !isp( i ) )
			composite[ size++ ] = i;
		else
			prime[ i ] = true;
	for( int i = 0; i < size; ++i )
		for( int j = 2; composite[ i ] * j <= N; ++j )
			cp[ composite[ i ] * j ] = true;
	while( scanf( "%d", &size ) == 1 )
	{
		int ans = 0;
		for( int i = 0; i < size; ++i )
			scanf( "%d", &n ), ans += !cp[ n ] & !prime[ n ];
		printf( "%d\n", ans );
	}
}
