#include<stdio.h>

int main()
{
	int t;
	long long n;
	for( scanf( "%d", &t ); t-- && scanf( "%lld", &n ); printf( "%lld\n", n * ( n + 2 ) ) );
}
