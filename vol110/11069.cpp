#include<cstdio>

int main()
{
	int ans[ 77 ] = { 1, 1, 2 }, n;
	for( int i = 3; i < 77; ++i )
		ans[ i ] = ans[ i-2 ] + ans[ i-3 ];

	while( scanf( "%d", &n ) != EOF )
		printf( "%d\n", ans[ n ] );

	return 0;
}
