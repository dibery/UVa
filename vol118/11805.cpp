#include<cstdio>

int main()
{
    int t, people, start, pass;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d %d %d", &people, &start, &pass );
        printf( "Case %d: %d\n", i, ( start + pass ) % people? ( start + pass ) % people : people );
    }

    return 0;
}
