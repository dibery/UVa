#include<cstdio>
inline void normal( int *num )
{
    for( int i = 0; i < 30; ++i )
    {
        num[ i+1 ] += num[ i ] / 10;
        num[ i ] %= 10;
    }
}
int coin[ 18 ] = { 0, 1 }, ans[ 100001 ][ 18 ][ 30 ] = { 1 }, n, t;
long long int mod;

int main()
{
    for( int i = 2; i < 18; ++i )
        coin[ i ] = coin[ i-1 ] << 1;
    for( int i = 0; i <= 100000; ++i )
        for( int j = 1; j < 18; normal( ans[ i ][ j++ ] ) )
            if( i >= coin[ j ] )
                for( int k = 0; k < 30; ++k )
                    ans[ i ][ j ][ k ] = ( ans[ i ][ j-1 ][ k ] + ans[ i - coin[ j ] ][ j ][ k ] );
            else
                for( int k = 0; k < 30; ++k )
                    ans[ i ][ j ][ k ] = ans[ i ][ j-1 ][ k ];

    scanf( "%d", &t );
    for( int i = 1; i <= t; ++i )
    {
        long long int tmp = 0;
        scanf( "%d %lld", &n, &mod );
        for( int i = 29; i >= 0; --i )
            tmp = ( ans[ n ][ 17 ][ i ] + tmp * 10 ) % mod;
        printf( "Case %d: %lld\n", i, tmp );
    }

	return 0;
}