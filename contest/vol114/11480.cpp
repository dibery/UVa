#include<cstdio>

int main()
{
    long long int n, t = 0;

    while( scanf( "%lld", &n ) && n )
        printf( "Case %lld: %lld\n", ++t, ( ( n-1 )*( n-2 ) / 2 - 3 * ( ( n-3 ) / 2 + 1 ) + ( n % 3 == 0? 2 : 0 ) ) / 6 );

    return 0;
}