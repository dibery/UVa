#include<cstdio>
#include<cstring>

int main()
{
    char a[ 300 ], b[ 300 ], c[ 300 ];
    int test, end, start;
    scanf( "%d", &test );

    while( test-- )
    {
        memset( a, 0, sizeof( a ) );
        memset( b, 0, sizeof( a ) );
        memset( c, 0, sizeof( a ) );
        scanf( "%s", a );
        scanf( "%s", b );
        for( int i = 0; a[ i ] || b[ i ]; ++i )
            c[ i ] = a[ i ] + b[ i ];
        for( int i = 0; c[ i ]; ++i )
            c[ i ] %= 48;
        for( int i = 0; c[ i ]; ++i )
            if( c[ i ] > 9 )
            {
                c[ i+1 ] += c[ i ] / 10;
                c[ i ] %= 10;
            }
        for( end = 203; !c[ end ]; --end );
        for( start = 0; !c[ start ]; ++start );
        for( ; start <= end; ++start )
            printf( "%d", c[ start ] );
        puts( "" );
    }

    return 0;
}
