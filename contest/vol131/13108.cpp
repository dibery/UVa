#include<cstdio>

int edge( int n )
{
	return ( n - 1 + ( n - 2 ) * ( n - 2 ) * ( n - 1 ) / 2 - ( n - 2 ) * ( n - 1 ) * ( 2 * n - 3 ) / 6 ) * n / 2 + n;
}

int vertex( int n )
{
	return ( ( n - 2 ) * ( n - 2 ) * ( n - 1 ) / 2 - ( n - 2 ) * ( n - 1 ) * ( 2 * n - 3 ) / 6 ) * n / 4 + n;
}

int main()
{
	int t, n;

	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); )
		printf( "%d\n", edge( n ) - vertex( n ) + 1 );
}
