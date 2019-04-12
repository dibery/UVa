#include<cstdio>

int main()
{
    int all, back, tmp;

    while( scanf( "%d %d", &all, &back ) == 2 )
    {
        bool state[ 10001 ] = { false };
        for( int i = 0; i < back; ++i )
            scanf( "%d", &tmp ), state[ tmp ] = true;
        if( all == back )
            putchar( '*' );
        else
            for( int i = 1; i <= all; ++i )
                if( !state[ i ] )
                    printf( "%d ", i );
        puts( "" );
    }

    return 0;
}
