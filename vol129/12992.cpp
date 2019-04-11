#include<cstdio>

int main()
{
	scanf( "%*d" );
	for( int n, t = 0; scanf( "%d", &n ) == 1; printf( "Case #%d: %d\n", ++t, 2*n-1 ) );
}
