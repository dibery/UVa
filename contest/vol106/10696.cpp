#include<cstdio>

int main()
{
    int n;
    while( scanf( "%d", &n ) && n )
        printf( "f91(%d) = %d\n", n, n <= 100? 91 : n-10 );

	return 0;
}