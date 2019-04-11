#include<cstdio>
#define T true
#define F false
const bool prime[ 32 ] = { F, F, T, T, F, T, F, T, F, F, F, T, F, T, F, F, F, T, F, T, F, F, F, T, F, F, F, F, F, T, F, T };
void bt( int *ring, int n, int now, bool *use )
{
    if( now != n )
        for( int i = 2; i <= n; ++i )
            if( !use[ i ] && prime[ i + ring[ now-1 ] ] )
            {
                use[ i ] = true;
                ring[ now ] = i;
                bt( ring, n, now+1, use );
                ring[ now ] = 0;
                use[ i ] = false;
            }
            else;
    else//
        if( prime[ ring[ n-1 ] + *ring ] )
            for( int i = 0; i < n; ++i )
                printf( "%d%s", ring[ i ], i == n-1? "\n" : " " );
}

int main()
{
    int n, t = 0;
    bool first = true;

    while( scanf( "%d", &n ) != EOF )
    {
        if( !first )
            puts( "" );
        first = false;
        int num[ 16 ] = { 1 };
        bool use[ 17 ] = { false, true };
        printf( "Case %d:\n", ++t );
        bt( num, n, 1, use );
    }

    return 0;
}
