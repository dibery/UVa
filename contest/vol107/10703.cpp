#include<cstdio>
#include<algorithm>

int main()
{
    int width, height, sub, sx, sy, ex, ey;

    while( scanf( "%d %d %d", &width, &height, &sub ) && width )
    {
        bool field[ 501 ][ 501 ] = { false };
        int ans = 0;
        for( int i = 0; i < sub; ++i )
        {
            scanf( "%d %d %d %d", &sx, &sy, &ex, &ey );
            if( sx > ex )
                std::swap( sx, ex );
            if( sy > ey )
                std::swap( sy, ey );
            for( int m = sx; m <= ex; ++m )
                for( int n = sy; n <= ey; ++n )
                    field[ m ][ n ] = true;
        }
        for( int i = 1; i <= width; ++i )
            for( int j = 1; j <= height; ++j )
                ans += !field[ i ][ j ];
        if( ans == 0 )
            puts( "There is no empty spots." );
        else if( ans == 1 )
            puts( "There is one empty spot." );
        else
            printf( "There are %d empty spots.\n", ans );
    }

	return 0;
}