#include<cstdio>
#include<cmath>
int x[ 1000001 ] = { 1 };

int main()
{
	for( int i = 1; i <= 1000000; ++i )
		x[ i ] = ( x[ int( i-sqrt( i ) ) ] + x[ int( log( i ) ) ] + x[ int( i*sin( i )*sin( i ) ) ] ) % 1000000;
	for( int t; scanf( "%d", &t ) && t != -1; )
		printf( "%d\n", x[ t ] );

	return 0;
}
