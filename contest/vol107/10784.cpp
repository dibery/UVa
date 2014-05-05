#include<cstdio>
#include<cstdlib>
#include<cmath>

int main()
{
	long long int n, t = 0;

	while( scanf( "%lld", &n ) && n )
		printf( "Case %lld: %.0f\n", ++t, ceil( ( sqrt( n * 8 + 9 ) - 1 ) / 2 ) + 2 );

	return 0;
}
