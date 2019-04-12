#include<cstdio>

int main()
{
    int t, man, own, tmp;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d", &man );
        int stamp[ 10001 ] = { 0 }, has[ 50 ] = { 0 }, total = 0;
        for( int i = 1; i <= man; ++i )
        {
            scanf( "%d", &own );
            for( int j = 0; j < own; ++j )
            {
                scanf( "%d", &tmp );
                if( !stamp[ tmp ] )
                    stamp[ tmp ] = i;
                else if( stamp[ tmp ] != -1 && stamp[ tmp ] != i )
                    stamp[ tmp ] = -1;
            }
        }
        for( int i = 0; i <= 10000; ++i )
            if( stamp[ i ] != 0 && stamp[ i ] != -1 )
                ++has[ stamp[ i ] ], ++total;
        printf( "Case %d:", i );
        for( int i = 1; i <= man; ++i )
            printf( " %.6lf%%", has[ i ] * 100.0 / total );
        puts( "" );
    }
}
