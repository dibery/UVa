#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
    char a[ 105 ], b[ 105 ];

    while( scanf( "%s", a ) != EOF )
    {
        int ans[ 211 ] = { 0 }, out = 210, len = strlen( a );
        if( *a == '0' )
            printf( "1" );
        if( strtol( a, NULL, 10 ) == 1 )
        {
            printf( "2\n" );
            continue;
        }
        reverse( a, a+len );
        strcpy( b, a );

        for( int i = 0; i < len; ++i )
            for( int j = 0; j < len; ++j )
                ans[ i+j ] += ( a[ j ]-'0' ) * ( b[ i ]-'0' );
        for( int i = 0; i < len; ++i )
            ans[ i ] -= a[ i ] - '0';
        for( int i = 0; i <= 210; ++i )
            if( ans[ i ] > 9 )
            {
                ans[ i+1 ] += ans[ i ] / 10;
                ans[ i ] %= 10;
            }
            else if( ans[ i ] < 0 )
            {
                ans[ i+1 ] += ans[ i ] / 10 - 1;
                ans[ i ] += 10;
            }
        while( --out >= 0 && !ans[ out ] );
        *ans += 2;
        for( int i = 0; i <= 210; ++i )
            if( ans[ i ] > 9 )
            {
                ans[ i+1 ] += ans[ i ] / 10;
                ans[ i ] %= 10;
            }
        for( int i = out; i >= 0; --i )
            printf( "%d", ans[ i ] );
        printf( "\n" );
    }

    return 0;
}
