#include<cstdio>

int main()
{
	long long fib[ 86 ] = { 0, 1 };

	for( int i = 2; i < 86; ++i )
		fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];

	for( int i; scanf( "%d", &i ) && i; printf( "%lld\n", fib[ i ] ) );
}
