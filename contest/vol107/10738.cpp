#include<cstdio>
int mu[ 1000001 ] = { 0, 1 }, m[ 1000001 ], prime[ 1000 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

bool sqfree( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n && i < size; ++i )
		if( n % ( prime[ i ] * prime[ i ] ) == 0 )
			return false;
	return true;
}

int factor( int n )
{
	int ans = 0;
	for( int i = 0; prime[ i ] * prime[ i ] <= n && i < size; ++i )
		while( n % prime[ i ] == 0 )
			n /= prime[ i ], ++ans;
	return ans + ( n != 1 );
}

int main()
{
	for( int i = 3; i < 1000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;
	for( int i = 2; i <= 1000000; ++i )
		if( sqfree( i ) )
			mu[ i ] = factor( i ) % 2 ? -1 : 1;
	for( int i = 1; i <= 1000000; ++i )
		m[ i ] = m[ i-1 ] + mu[ i ];

	int n;
	while( scanf( "%d", &n ) && n )
		printf( "%8d%8d%8d\n", n, mu[ n ], m[ n ] );
}
