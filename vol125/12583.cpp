#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
    int t, day, mem;
    char man[ 505 ], *found;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        int reg = 0;
        scanf( "%d %d %s", &day, &mem, man );
        for( int i = 0; i < day; ++i )
        {
            found = std::find( man + ( i - mem >= 0? i - mem : 0 ), man + i, man[ i ] );
            if( found != man + i )
                ++reg;
        }
        printf( "Case %d: %d\n", i, reg );
    }

    return 0;
}
