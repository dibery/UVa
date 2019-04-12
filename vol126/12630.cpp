#include<cstdio>

int main()
{
	int n;

	while( scanf( "%d", &n ) && n )
		printf( "%d\n", (n-1) * n * (n+1) * (n+2) / 24 );
	
	return 0;
}
