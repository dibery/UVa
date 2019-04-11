#include<cstdio>

int main()
{
    int n, ans[ 31 ] = { 1 };
    for( int i = 2; i <= 30; i += 2 )
    {
        for( int j = i-2; j >= 0; j -= 2 )
            ans[ i ] += ans[ j ] << 1;
        ans[ i ] += ans[ i-2 ];
    }

    while( scanf( "%d", &n ) && n != -1 )
        printf( "%d\n", ans[ n ] );

    return 0;
}