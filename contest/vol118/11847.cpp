#include<cstdio>
#include<algorithm>

int main()
{
	int N[ 16 ] = { 1 }, n;

	for( int i = 1; i < 16; ++i )
		N[ i ] = N[ i-1 ] << 1;

	while( scanf( "%d", &n ) && n )
		printf( "%d\n", std::upper_bound( N, N + 16, n ) - N - 1 );
}
