#include<cstdio>
#include<algorithm>
inline int abs( int a ) { return a < 0? -a : a; }
int path( int *order, int *x, int *y, int dist[ 11 ][ 11 ], int total )
{
    int ans = 0;
    for( int i = 1; i <= total; ++i )
        ans += dist[ order[ i-1 ] ][ order[ i ] ];
    ans += dist[ order[ total ] ][ 0 ];
    return ans;
}

int main()
{
    int test;
    scanf( "%d", &test );

    while( test-- )
    {
        int order[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, x[ 11 ], y[ 11 ], ans = 1 << 30, beeper, dist[ 11 ][ 11 ];
        scanf( "%d %d", x, y );
        scanf( "%d %d", x, y );
        scanf( "%d", &beeper );
        for( int i = 1; i <= beeper; ++i )
            scanf( "%d %d", x+i, y+i );
        for( int i = 0; i <= 10; ++i )
            for( int j = i+1; j <= 10; ++j )
                dist[ j ][ i ] = dist[ i ][ j ] = abs( x[ i ] - x[ j ] ) + abs( y[ i ] - y[ j ] );
        do
            ans = std::min( ans, path( order, x, y, dist, beeper ) );
        while( std::next_permutation( order+1, order+beeper+1 ) );
        printf( "The shortest path has length %d\n", ans );
    }

	return 0;
}