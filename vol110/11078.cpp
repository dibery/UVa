#include<cstdio>
#include<algorithm>

int main()
{
    int prev, now, test, size;
    scanf( "%d", &test );

    while( test-- )
    {
        int old, young, ans = -10000000;
        scanf( "%d %d", &size, &old );
        for( int i = 1; i < size; ++i )
        {
            scanf( "%d", &young );
            if( ans == -10000000 )
                ans = old-young;
            if( young > old )
                old = young;
            else
                ans = std::max( ans, old-young );
        }
        printf( "%d\n", ans );
    }
    return 0;
}
