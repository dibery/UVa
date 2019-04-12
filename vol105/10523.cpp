#include<cstdio>
inline void normal( int *tmp )
{
    for( int n = 0; n < 180; ++n )
    {
        tmp[ n+1 ] += tmp[ n ] / 10;
        tmp[ n ] %= 10;
    }
}

int main()
{
    int item, base;

    while( scanf( "%d %d", &item, &base ) != EOF )
    {
        if( !base )
        {
            puts( "0" );
            continue;
        }
        int ans[ 180 ] = { 0 }, out = 179, tmp[ 180 ] = { 1 };
        for( int i = 1; i <= item; ++i )
        {
            for( int n = 0; n < 180; ++n )
                tmp[ n ] *= base;
            normal( tmp );
            for( int k = 0; k < 180; ++k )
                ans[ k ] += i * tmp[ k ];
            normal( ans );
        }
        for( ; !ans[ out ]; --out );
        for( ; out >= 0; --out )
            printf( "%d", ans[ out ] );
        puts( "" );
    }

    return 0;
}
