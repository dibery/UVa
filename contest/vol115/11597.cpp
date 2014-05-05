#include<cstdio>

int main()
{
    int t = 0, n;

    while( scanf( "%d", &n ) && n )
        printf( "Case %d: %d\n", ++t, n >> 1 );

    return 0;
}
