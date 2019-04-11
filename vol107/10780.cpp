#include<cstdio>
#include<algorithm>
int t, fact, base, single[ 10000 ][ 10000 ] = { { 0 } }, cum[ 10000 ][ 10000 ] = { { 0 } };
//notice when fact = 1!!!!!!
int main()
{
    for( int i = 2; i < 10000; ++i )
    {
        for( int j = 2, tmp = i; tmp != 1; ++j )
            while( tmp % j == 0 )
                tmp /= j, ++single[ i ][ j ];
        for( int j = 2; j <= i; ++j )
            cum[ i ][ j ] = cum[ i-1 ][ j ] + single[ i ][ j ];
    }
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        int ans = 1e9;
        scanf( "%d %d", &base, &fact );
        for( int k = 2; k <= base && ans; ++k )
            if( single[ base ][ k ] )
                ans = std::min( ans, cum[ fact ][ k ] / single[ base ][ k ] );
        if( !ans )
            printf( "Case %d:\nImpossible to divide\n", i );
        else
            printf( "Case %d:\n%d\n", i, ans );
    }
    return 0;
}