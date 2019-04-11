#include<cstdio>

int main()
{
	int m, n;

	for( scanf( "%*d" ); scanf( "%d %d", &m, &n ) == 2; )
		if( m == n )
			printf( "%d\n", (1+(n+1)/2) * ((n+1)/2) / 2 );
		else if( m % 2 || n % 2 )
			printf( "%d\n", (m+1) / 2 * ( (n+1) / 2 ) );
		else
			printf( "%d\n", m * n / 4 );
}
