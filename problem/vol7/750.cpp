#include<cstdio>
int all = 0;
char ans[ 92 ][ 9 ] = { 0 };
bool conflict( int now, int Try, int *queen )
{
    for( int i = 0; i < now; ++i )
        if( queen[ i ] == Try || i + queen[ i ] == now + Try || i - queen[ i ] == now - Try )
            return true;
    return false;
}
void put( int *queen, int now )
{
    if( now == 8 )
{
    for( int i = 0; i < 8; ++i )
            ans[ all ][ i ] = queen[ i ]+1;
        ++all;
        return;
    }
    for( int i = 0; i < 8; ++i )
        if( !conflict( now, i, queen ) )
        {
            queen[ now ] = i;
            put( queen, now+1 );
            queen[ now ] = 0;
        }
}

int main()
{
    int size, t, x, y, queen[ 8 ] = { 0 };
    scanf( "%d", &t );
    put( queen, 0 );

    while( t-- )
    {
        scanf( "%d %d", &x, &y );
        puts( "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n" );
        for( int t = 0, now = 0; now < 92; ++now )
            if( ans[ now ][ y-1 ] == x )
                printf( "%2d      %d %d %d %d %d %d %d %d\n", ++t, ans[ now ][ 0 ], ans[ now ][ 1 ], ans[ now ][ 2 ], ans[ now ][ 3 ], ans[ now ][ 4 ], ans[ now ][ 5 ], ans[ now ][ 6 ], ans[ now ][ 7 ] );
        if( t )
            puts( "" );
    }

    return 0;
}
