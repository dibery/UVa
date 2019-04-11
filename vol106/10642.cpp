#include<cstdio>

int main()
{
    int t, sx, sy, dy, dx, lines, lined;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        int ans = 0;
        scanf( "%d %d %d %d", &sx, &sy, &dx, &dy );
        lines = sx + sy;
        lined = dx + dy - 1;
        if( lines == lined+1 )
        {
            printf( "Case %d: %d\n", i, dx - sx );
            continue;
        }
        ans += lines - sx;
        ans += dx + 1;
        for( int k = lines; k < lined; ++k )
            ans += k + 2;
        printf( "Case %d: %d\n", i, ans );
    }

	return 0;
}