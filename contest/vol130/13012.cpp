#include<cstdio>

int main()
{
	for( int ans, a, b, c, d, e; scanf( "%d %d %d %d %d %d", &ans, &a, &b, &c, &d, &e ) == 6; )
		printf( "%d\n", ( a == ans ) + ( b == ans ) + ( c == ans ) + ( d == ans ) + ( e == ans ) );
}
