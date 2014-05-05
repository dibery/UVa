#include<cstdio>
bool ok( int init, int h )
{
    while( init % h == 0 )
        init /= h;
    return init == 1;
}
int lev( int init, int h )
{
    int dep = 0;
    while( init != 1 )
        init /= h, ++dep;
    return dep;
}
int pow( int base, int exp )
{
    int back = base;
    for( int i = 2; i <= exp; ++i )
        back *= base;
    return back;
}

int main()
{
    int N, init, work, level;

    while( scanf( "%d %d", &init, &work ) && init+work )
    {
        for( N = 1; N < init; ++N )
            if( ok( init, N+1 ) )
                if( pow( N, level = lev( init, N+1 ) ) == work )
                    break;
        int idle = N == 1? level : ( pow( N, level ) - 1 ) / ( N-1 ), h = work + init;
        for( int i = level-1; i; --i )
            h += init / pow( N+1, i ) * pow( N, i );
        if( init != 1 )
            printf( "%d %d\n", idle, h );
        else//
            printf( "%d %d\n", 1-work, 1 );
    }

    return 0;
}