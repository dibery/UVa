#include<cstdio>
#include<cmath>

int main()
{
	int m, n;

	while( scanf( "%d %d", &m, &n ) == 2 )
	{
		double digit = 0;
		for( int i = 1; i <= n; ++i )
			digit += log10( m-i+1 ) - log10( i );
		printf( "%d\n", int( digit+1+1e-4 ) );
	}
}
