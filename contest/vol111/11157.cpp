#include<cstdio>
#include<algorithm>
using namespace std;
inline int abs( int a ) { return a<0? -a : a; }

int main()
{
    int t, stone, dist, place[ 110 ] = { 0 }, in, prev, ans;
    char type;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d %d\n", &stone, &dist );
        if( stone == 0 )
        {
            printf( "Case %d: %d\n", i, dist );
            continue;
        }
        prev = 0;
        ans = 0;
        place[ stone+1 ] = dist;
        for( int k = 1; k <= stone; ++k )
        {
            scanf( "%c-%d ", &type, &in );
            place[ k ] = type == 'B'? in : -in;
            if( type == 'B' )
            {
                if( k-prev == 1 )
                    ans = max( ans, abs( place[ k ] ) - abs( place[ prev ] ) );
                else
                    for( ; place[ prev+1 ] < 0; ++prev )
                        ans = max( ans, abs( place[ prev+2 ] ) - abs( place[ prev ] ) );
                prev = k;
            }
        }
        if( prev == stone )
            ans = max( ans, dist - abs( place[ prev ] ) );
        else
            for( ; place[ prev+1 ] < 0; ++prev )
                ans = max( ans, abs( place[ prev+2 ] ) - abs( place[ prev ] ) );
        printf( "Case %d: %d\n", i, ans );
    }

	return 0;
}