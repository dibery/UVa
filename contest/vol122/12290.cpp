#include<cstdio>
inline bool clap( int n )
{
    if( n % 7 == 0 )
        return true;
    while( n )
    {
        if( n % 10 == 7 )
            return true;
        n /= 10;
    }
    return false;
}

int main()
{
    int people, seq, time;

    while( scanf( "%d %d %d", &people, &seq, &time ) && time )
    {
        int timing1 = seq, timing2 = 2 * people - seq, lamba = 2 * people - 2;
        int clapped = 0, i;
        bool first = true;
        for( i = 0; ; ++i )
        {
            if( clap( i * lamba + timing1 ) )
                ++clapped;
            first = true;
            if( clapped == time )
                break;
            if( seq == 1 || seq == people )
                continue;
            if( clap( i * lamba + timing2 ) )
                ++clapped;
            first = false;
            if( clapped == time )
                break;
        }
        printf( "%d\n", i * lamba + ( first? timing1 : timing2 ) );
    }

    return 0;
}
