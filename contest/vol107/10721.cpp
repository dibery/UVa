#include<cstdio>

int main()
{
    long long int n, k, m, ans[ 51 ][ 51 ][ 51 ] = { 0 };

    for( int i = 1; i <= 50; ++i )
        for( int j = i; j <= 50; ++j )
            ans[ i ][ 1 ][ j ] = 1;
    for( int i = 2; i <= 50; ++i )
        for( int j = 1; j <= 50; ++j )
            for( int k = 1; k <= 50; ++k )
                for( int m = 1; m <= k; ++m )
                    if( i-m > 0 )
                        ans[ i ][ j ][ k ] += ans[ i-m ][ j-1 ][ k ];
    while( scanf( "%lld %lld %lld", &n, &k, &m ) != EOF )
        printf( "%lld\n", ans[ n ][ k ][ m ] );
    return 0;
}