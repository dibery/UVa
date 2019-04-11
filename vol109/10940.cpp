#include<cstdio>

int main()
{
    int n, ans[ 500001 ] = { 0, 1, 2, 2, 4, 2 };
    for( int i = 6; i <= 500000; ++i )
        ans[ i ] = i % 2 == 0? ( ans[ i >> 1 ] << 1 ) % i : ( 2 + ans[ i-1 ] ) % i;

    while( scanf( "%d", &n ) && n )
        printf( "%d\n", ans[ n ] );

    return 0;
}
