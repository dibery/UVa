#include<cstdio>

int main()
{
    long long int fib[ 52 ] = { 1, 2 };
    int t, n;
    for( int i = 2; i <= 51; ++i )
        fib[ i ] = fib[ i-1 ] + fib[ i-2 ];
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d", &n );
        printf( "Scenario #%d:\n%lld\n\n", i, fib[ n ] );
    }

    return 0;
}
