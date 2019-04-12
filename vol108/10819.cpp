#include<cstdio>
#include<climits>
#include<algorithm>

int main()
{
    int budget, item;

    while( scanf( "%d %d", &budget, &item ) != EOF )
    {
        if( budget > 1800 )
            budget += 200;
        int price[ item ], favor[ item ], pack[ budget+1 ], ans = 0;
        for( int i = 0; i < item; ++i )
            scanf( "%d %d", price+i, favor+i );
        for( int i = 1; i <= budget; ++i )
            pack[ i ] = INT_MIN;
        *pack = 0;
        for( int i = 0; i < item; ++i )
            for( int j = budget; j >= price[ i ]; --j )
                pack[ j ] = std::max( pack[ j ], pack[ j - price[ i ] ] + favor[ i ] );
        for( int i = 0; i <= budget; ++i )
            if( i > 2000 || i <= budget && budget <= 1800 || i <= 2000 && i <= budget - 200 )
                ans = std::max( ans, pack[ i ] );
        printf( "%d\n", ans );
    }

    return 0;
}