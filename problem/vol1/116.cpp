#include<cstdio>
#include<cstring>
#include<algorithm>
template<typename T>
inline T min( T a, T b, T c ) { return std::min( std::min( a, b ), c ); }

int main()
{
    int h, w, num[ 10 ][ 100 ], next[ 10 ][ 100 ], sum[ 10 ][ 100 ];

    while( scanf( "%d %d", &h, &w ) != EOF )
    {
        int tar = 0, MIN = 1000000000;
        memset( next, 0, sizeof( next ) );
        memset( sum, 0, sizeof( sum ) );

        for( int i = 0; i < h; ++i )
            for( int j = 0; j < w; ++j )
                scanf( "%d", num[ i ]+j );
        for( int i = 0; i < h; ++i )
            sum[ i ][ w-1 ] = num[ i ][ w-1 ];
        for( int i = w-2; i >= 0; --i )
            for( int j = 0; j < h; ++j )
            if( j == 0 )
            {
                sum[ j ][ i ] = min( sum[ h-1 ][ i+1 ], sum[ 0 ][ i+1 ], h > 1? sum[ 1 ][ i+1 ] : sum[ 0 ][ i+1 ] );
                if( sum[ j ][ i ] == sum[ 0 ][ i+1 ] )
                    next[ j ][ i ] = 0;
                else if( sum[ j ][ i ] == sum[ 1 ][ i+1 ] )
                    next[ j ][ i ] = 1;
                else
                    next[ j ][ i ] = h-1;
                sum[ j ][ i ] += num[ j ][ i ];
            }
            else if( j == h-1 )
            {
                sum[ j ][ i ] = min( sum[ 0 ][ i+1 ], sum[ j ][ i+1 ], sum[ j-1 ][ i+1 ] );
                if( sum[ j ][ i ] == sum[ 0 ][ i+1 ] )
                    next[ j ][ i ] = 0;
                else if( sum[ j ][ i ] == sum[ j-1 ][ i+1 ] )
                    next[ j ][ i ] = j-1;
                else
                    next[ j ][ i ] = j;
                sum[ j ][ i ] += num[ j ][ i ];
            }
            else
            {
                sum[ j ][ i ] = min( sum[ j-1 ][ i+1 ], sum[ j ][ i+1 ], sum[ j+1 ][ i+1 ] );
                if( sum[ j ][ i ] == sum[ j-1 ][ i+1 ] )
                    next[ j ][ i ] = j-1;
                else if( sum[ j ][ i ] == sum[ j ][ i+1 ] )
                    next[ j ][ i ] = j;
                else
                    next[ j ][ i ] = j+1;
                sum[ j ][ i ] += num[ j ][ i ];
            }
        for( int i = 0; i < h; ++i )
            if( MIN > sum[ i ][ 0 ] )
                MIN = sum[ i ][ 0 ], tar = i;
        for( int i = 0; i < w; ++i )
            printf( "%d%c", tar+1, i == w-1? '\n' : ' ' ), tar = next[ tar ][ i ];
        printf( "%d\n", MIN );
    }

    return 0;
}
