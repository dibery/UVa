#include<cstdio>

int main()
{
    int event, t = 0, in, ans[ 2 ];

    while( scanf( "%d", &event ) != EOF && event )
    {
        ans[ 0 ] = ans[ 1 ] = 0;
        for( int i = 0; i < event; ++i )
        {
            scanf( "%d", &in );
            ++ans[ in? 0 : 1 ];
        }
        printf( "Case %d: %d\n", ++t, ans[ 0 ] - ans[ 1 ] );
    }

    return 0;
}
