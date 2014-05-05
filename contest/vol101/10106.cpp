#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char a[ 300 ], b[ 300 ];

    while( scanf( "%s %s", a, b ) != EOF )
    {
        int ans[ 511 ] = { 0 }, out = 510, leading;
        for( leading = 0; a[ leading ] == '0' && a[ leading ]; ++leading );
        if( leading && a[ leading ] )
            strcpy( a, a+leading );
        for( leading = 0; b[ leading ] == '0' && b[ leading ]; ++leading );
        if( leading && b[ leading ] )
            strcpy( b, b+leading );
        if( *a == '0' || *b == '0' )
            printf( "0" );
        int la = strlen( a ), lb = strlen( b );
        reverse( a, a+la );
        reverse( b, b+lb );
        for( int i = 0; i < lb; ++i )
            for( int j = 0; j < la; ++j )
                ans[ i+j ] += ( a[ j ]-'0' ) * ( b[ i ]-'0' );
        for( int i = 0; i <= 502; ++i )
            if( ans[ i ] > 9 )
            {
                ans[ i+1 ] += ans[ i ] / 10;
                ans[ i ] %= 10;
            }
        while( --out >= 0 && !ans[ out ] );
        for( int i = out; i >= 0; --i )
            printf( "%d", ans[ i ] );
        printf( "\n" );
    }

    return 0;
}
