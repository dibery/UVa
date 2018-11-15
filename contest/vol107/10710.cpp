#include<cstdio>

bool ok( int n )
{
	long long mod[ 31 ] = { 2 }, ans = 1;

	for( int i = 1; i < 31; ++i )
		mod[ i ] = mod[ i - 1 ] * mod[ i - 1 ] % n;
	for( int i = 0; i < 31; ++i )
		if( n & 1 << i )
			ans = ans * mod[ i ] % n;

	return ans == 2;
}

int main()
{
	for( int n; scanf( "%d", &n ) && ~n; )
		printf( "%d is%s a Jimmy-number\n", n, ok( n )? "" : " not" );
}
