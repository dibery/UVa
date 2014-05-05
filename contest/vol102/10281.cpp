#include<cstdio>
inline double timetosec( int h, int m, int s ) { return 3600 * h + 60 * m + s; }

int main()
{
    char in[ 20 ];
    int pair, h, m, s, ph = 0, pm = 0, ps = 0, speed, pv = 0;
    double dist = 0;

    while( gets( in ) )
    {
        pair = sscanf( in, "%d:%d:%d %d", &h, &m, &s, &speed );
        dist += timetosec( h-ph, m-pm, s-ps ) * pv / 3600.0;
        ph = h;
        pm = m;
        ps = s;
        if( pair == 3 )
            printf( "%02d:%02d:%02d %.2f km\n", h, m, s, dist );
        else
            pv = speed;
    }

    return 0;
}
