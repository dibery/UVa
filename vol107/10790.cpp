#include<cstdio>

int main()
{
	long long int a, b;
	int t = 0;

	while( scanf( "%lld %lld", &a, &b ) && a )
		printf( "Case %d: %lld\n", ++t, a * (a-1) / 2 * b * (b-1) / 2 );
}
