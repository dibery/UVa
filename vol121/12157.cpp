#include<cstdio>
inline int m( int time ) { return ( time + 30 - time % 30 ) / 3; }
inline int j( int time ) { return ( time + 60 - time % 60 ) / 4; }

int main()
{
    int t, call, dur;
    register int mile, juice;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        mile = juice = 0;
        scanf( "%d", &call );
        for( int i = 0; i < call; ++i )
        {
            scanf( "%d", &dur );
            mile += m( dur );
            juice += j( dur );
        }
        if( mile < juice )
            printf( "Case %d: Mile %d\n", i, mile );
        else if( mile > juice )
            printf( "Case %d: Juice %d\n", i, juice );
        else
            printf( "Case %d: Mile Juice %d\n", i, mile );
    }

	return 0;
}