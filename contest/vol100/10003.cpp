#include<cstdio>
#include<climits>
#include<algorithm>

int main()
{
        int len, pos[ 51 ] = { 0 }, total;

        while( scanf( "%d", &len ) && len )
        {
                int dp[ 51 ][ 51 ] = { { 0 } };
                scanf( "%d", &total );
                for( int i = 1; i <= total; ++i )
                        scanf( "%d", pos+i );
                pos[ total+1 ] = len;
                for( int i = 1; i <= total+1; ++i )
                        for( int j = 0; j <= total+1; ++j )
                                dp[ i ][ j ] = INT_MAX;
                for( int i = 1; i <= total+1; ++i )
                        dp[ i ][ i+1 ] = pos[ i+1 ] - pos[ i-1 ], dp[ i ][ i ] = 0;
                for( int dist = 2; dist <= total; ++dist )
                        for( int begin = 1; begin + dist - 1 <= total; ++begin )
                                for( int cut = begin; cut < begin + dist; ++cut )
                                        dp[ begin ][ begin + dist ] = std::min( dp[ begin ][ begin + dist ], dp[ begin ][ cut ] + dp[ cut + 1 ][ begin + dist ] + pos[ begin + dist ] - pos[ begin - 1 ] );
                printf( "The minimum cutting is %d.\n", dp[ 1 ][ total + 1 ] );
        }
}