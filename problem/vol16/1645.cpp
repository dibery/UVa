#include<cstdio>
#define MOD 1000000007

int main()
{
    long long ans[ 1001 ] = { 0, 1 };
    int t = 0, n;
    for( int i = 2; i <= 1000; ++i )
        for( int j = 1; j < i; ++j )
            if( ( i - 1 ) % j == 0 )
                ans[ i ] = ( ans[ i ] + ans[ ( i - 1 ) / j ] ) % MOD;
    while( scanf( "%d", &n ) == 1 )
        printf( "Case %d: %d\n", ++t, int( ans[ n ] % MOD ) );
}
