#include<cstdio>
#include<cmath>
#include<algorithm>

int main()
{
    int ans, x, y, i, j;

    while( scanf( "%d %d", &x, &y ) && ( x || y ) )
    {
        i = x;
        j = y;
        if( x > y )
            std::swap( x, y );
        if( x == 1 )
            ans = y;
        else if( x == 2 )
            ans = 2 * ( 2 * ( y / 4 ) + ( y % 4 > 2? 2 : y % 4 ) );
        else
            ans = ceil( x * y / 2.0 );
        printf( "%d knights may be placed on a %d row %d column board.\n", ans, i, j );
    }

    return 0;
}
