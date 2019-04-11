#include<cstdio>
#include<cmath>
#include<algorithm>

int main()
{
    int light, t = 0, g[ 6 ], y[ 6 ], r[ 6 ];
    double loc[ 6 ];

    while( scanf( "%d", &light ) && light != -1 )
    {
        bool invalid[ 61 ] = { false };
        int out = 0;

        for( int i = 0; i < light; ++i )
            scanf( "%lf %d %d %d", loc+i, g+i, y+i, r+i );
        for( int speed = 30; speed <= 60; ++speed )
            for( int i = 0; i < light; ++i )
                if( fmod( loc[ i ] * 3600 / speed, g[ i ] + y[ i ] + r[ i ] ) > g[ i ] + y[ i ] )
                    invalid[ speed ] = true;

        printf( "Case %d:", ++t );
        for( int i = 30; i <= 60; ++i )
            if( !invalid[ i ] )
            {
                int end = std::find( invalid+i, invalid+61, true ) - invalid;
                if( i == end-1 )
                    printf( " %d", i );
                else
                    printf( " %d-%d", i, end-1 ), i = end;
                putchar( std::find( invalid+end, invalid+61, false ) == invalid+61? '\n' : ',' );
                ++out;
            }
        if( !out )
            puts( " No acceptable speeds." );
    }

    return 0;
}
