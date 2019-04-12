#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int test, size, target, A[ 41 ], B[ 41 ], tmp, DP[ 301 ][ 301 ];

int main()
{
    double I;
    scanf( "%d", &test );

    while( test-- )
    {
        scanf( "%d %d", &size, &target );
        int ans = 1 << 30, sq = target*target;
        memset( DP, 0, sizeof( DP ) );
        for( int i = 0; i < size; ++i )
        {
            scanf( "%d %d", A+i, B+i );
            if( A[ i ] == 0 && B[ i ] == 0 )
            {
                --i;
                --size;
            }
            DP[ A[ i ] ][ B[ i ] ] = 1;
        }
        for( int a = 0; a <= target; ++a )
            for( int b = 0; b <= target; ++b )
                if( DP[ a ][ b ] == 0 )
                    for( int k = 0; k < size; ++k )
                        if( a >= A[ k ] && b >= B[ k ] && DP[ a-A[ k ] ][ b-B[ k ] ] )
                            DP[ a ][ b ] = DP[ a ][ b ]? min( 1+DP[ a-A[ k ] ][ b-B[ k ] ], DP[ a ][ b ] ) : 1+DP[ a-A[ k ] ][ b-B[ k ] ];
        for( double i = 0; i <= target; ++i )
            if( modf( sqrt( sq - i*i ), &I ) == 0 )
                ans = DP[ int( i ) ][ int( I ) ]? min( DP[ int( i ) ][ int( I ) ], ans ) : ans;
        if( ans == 1 << 30 )
            puts( "not possible" );
        else
            printf( "%d\n", ans );
    }
    return 0;
}
