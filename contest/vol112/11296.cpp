#include<cstdio>
long long int calc( long long int n ) { return ( n*n + n ) / 2; }

int main()
{
	int n;

	while( scanf( "%d", &n ) == 1 )
		printf( "%lld\n", calc( n / 2 + 1 ) );
}
