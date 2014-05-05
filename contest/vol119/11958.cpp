#include<cstdio>
#include<algorithm>
int process( int nh, int nm, int th, int tm, int time )
{
    if( th < nh || th == nh && tm < nm )
        th += 24;
    return ( th - nh ) * 60 + tm - nm + time;
}

int main()
{
    int t, bus, nowh, nowm, tmph, tmpm, time;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        int need = 3000;
        scanf( "%d %d:%d", &bus, &nowh, &nowm );
        for( int k = 0; k < bus; ++k )
        {
            scanf( "%d:%d %d", &tmph, &tmpm, &time );
            need = std::min( need, process( nowh, nowm, tmph, tmpm, time ) );
        }
        printf( "Case %d: %d\n", i, need );
    }

	return 0;
}