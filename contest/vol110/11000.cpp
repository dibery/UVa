#include<cstdio>

int main()
{
    unsigned int n, ans[ 46 ] = { 0 }, fib[ 45 ] = { 1, 1 };
    for( int i = 2; i < 45; ++i )
        fib[ i ] = fib[ i-1 ] + fib[ i-2 ];
    for( int i = 1; i < 46; ++i )
        ans[ i ] = ans[ i-1 ] + fib[ i-1 ];

    while( scanf( "%u", &n ) && n != -1 )
        printf( "%u %u\n", ans[ n ], ans[ n+1 ] );

    return 0;
}
