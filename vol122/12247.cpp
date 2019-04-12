#include<cstdio>
#include<cstring>
#include<algorithm>
inline int next( int index, bool *pile )
{
    while( ++index < 53 && pile[ index ] );
    return ( index == 53? -1 : index );
}

int main()
{
    int a[ 3 ], b[ 2 ];
    bool dealt[ 53 ];

    while( scanf( "%d %d %d %d %d", a, a+1, a+2, b, b+1 ) && *a )
    {
        memset( dealt, false, sizeof( dealt ) );
        std::sort( a, a+3 );
        std::sort( b, b+2 );
        dealt[ a[ 0 ] ] = dealt[ a[ 1 ] ] = dealt[ a[ 2 ] ] = dealt[ b[ 0 ] ] = dealt[ b[ 1 ] ] = true;
        if( b[ 1 ] < a[ 0 ] || b[ 1 ] < a[ 1 ] )
            puts( "-1" );
        else if( b[ 1 ] < a[ 2 ] )
            if( b[ 0 ] < a[ 1 ] )
                puts( "-1" );
            else
                printf( "%d\n", next( a[ 1 ], dealt ) );
        else//
            if( b[ 0 ] > a[ 2 ] )
                printf( "%d\n", next( 0, dealt ) );
            else if( b[ 0 ] > a[ 1 ] )
                printf( "%d\n", next( a[ 1 ], dealt ) );
            else
                printf( "%d\n", next( a[ 2 ], dealt ) );
    }
    return 0;
}
