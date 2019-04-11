#include<cstdio>

int ans( long long n ) { return n? ans( n >> 1 ) + ( n & 1 ) : 0; }

int main()
{
	scanf( "%*d" );
	for( long long n; scanf( "%lld", &n ) == 1; printf( "%d\n", ans( n ) ) );
}
