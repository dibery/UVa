#include<cstdio>
#include<queue>
inline double sq( double a ) { return a*a; }
void bfs( int index, int *x, int *y, int dist, int sign, int star, int *bond )
{
    std::queue<int>search;
    bond[ index ] = sign;
    for( int i = 0; i < star; ++i )
        if( !bond[ i ] && sq( x[ index ] - x[ i ] ) + sq( y[ index ] - y[ i ] ) <= dist )
        {
            search.push( i );
            bond[ i ] = sign;
        }
    while( !search.empty() )
    {
        bfs( search.front(), x, y, dist, sign, star, bond );
        search.pop();
    }
}

int main()
{
    int t, star, dist, x[ 1000 ], y[ 1000 ];
    double tmp, tmp2;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        int bond[ 1000 ] = { 0 }, sign = 0;
        scanf( "%d %lf", &star, &tmp );
        dist = sq( tmp * 100 + 1e-7 ) + 1e-7;
        for( int i = 0; i < star; ++i )
        {
            scanf( "%lf %lf", &tmp, &tmp2 );
            x[ i ] = tmp * 100 + 1e-7;
            y[ i ] = tmp2 * 100 + 1e-7;
        }
        for( int i = 0; i < star; ++i )
            if( bond[ i ] == 0 )
                bfs( i, x, y, dist, ++sign, star, bond );
        printf( "Case %d: %d\n", i, sign );
    }

	return 0;
}
