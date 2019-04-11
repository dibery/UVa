#include<cstdio>

int main()
{
	int ans[ 32768 ] = { 0 }, t, n;

	for( int i = 1; i < 32768; ++i )
		ans[ i ] = ans[ i - 1 ] + ( i - 1 ) / 2;
	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); )
		printf( "%d\n", ans[ n ] );
}
