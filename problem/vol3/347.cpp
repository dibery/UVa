#include<cstdio>
int pow10[] = { 1, 10, 100,1000, 10000, 100000, 1000000, 10000000, 100000000 };
inline int D( int n )
{
    for( int i = 0; ; ++i )
        if( n < pow10[ i ] )
            return i;
}
bool run( int n )
{
    int digit = D(n), leftmost = n / pow10[ digit-1 ], now = 0, i, str[ 10 ] = { 0 };
    bool visit[ 10 ] = { false }, yes = true, exist[ 10 ] = { false };

    for( i = 1; i <= digit; ++i )
    {
        str[ i-1 ] = n / pow10[ digit-i ] % 10;
        if( !str[ i-1 ] || exist[ str[ i-1] ] )
            return false;
        exist[ str[ i-1] ] = true;
    }
    for( i = 1, now = 0; i <= digit && yes; ++i )
    {
        if( visit[ now ] )
            return false;
        visit[ now ] = true;
        now = ( now + str[ now ] ) % digit;
    }
    return str[ now ] == leftmost;
}

int main()
{
    int n, t = 0;

    while( scanf( "%d", &n ) && n )
    {
        while( !run( n ) )
            ++n;
        printf( "Case %d: %d\n", ++t, n );
    }

    return 0;
}
