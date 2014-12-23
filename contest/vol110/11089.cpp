#include<cstdio>
#include<algorithm>
using namespace std;

int fib[ 45 ] = { 0, 1 }, n, t;

void print( int n, int len )
{
	if( !n )
		puts( "" );
	else if( n == 1 )
		puts( "1" );
	else
	{
		printf( "10" );
		n -= fib[ len-1 ] + 1;
		int l = lower_bound( fib, fib+len, n ) - fib;
		for( int i = len - 2 - l; i--; )
			putchar( '0' );
		print( n, l );
	}
}

int main()
{
	for( int i = 2; i < 45; ++i )
		fib[ i ] = fib[ i-1 ] + fib[ i-2 ];
	for( int i = 2; i < 45; ++i )
		fib[ i ] += fib[ i-1 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &n );
		print( n, lower_bound( fib, fib+47, n ) - fib );
	}
}
