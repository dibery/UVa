#include<cstdio>

int main()
{
	long long n[ 61 ] = { 0, 1, 1, 1 };

	for( int i = 4; i <= 60; ++i )
		n[ i ] = n[ i - 1 ] + n[ i - 2 ] + n[ i - 3 ];
	for( int i, t = 0; scanf( "%d", &i ) && i; printf( "Case %d: %lld\n", ++t, n[ i ] ) );
}
