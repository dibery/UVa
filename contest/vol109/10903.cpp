#include<cstdio>
inline int judge( char me, char opp )
{
    if( me == opp )
        return 0;
    if( me == 's' && opp == 'p' || me == 'r' && opp == 's' || me == 'p' && opp == 'r' )
        return 1;
    return -1;
}

int main()
{
    int player, game, p1, p2;
    char g1[ 10 ], g2[ 10 ];
    bool first = true;

    while( scanf( "%d", &player ) && player )
    {
        if( !first )
            puts( "" );
        first = false;
        int win[ 101 ] = { 0 }, lose[ 101 ] = { 0 };
        scanf( "%d", &game );
        for( int i = game * player * ( player-1 ) / 2, result; i; --i )
        {
            scanf( "%d %s %d %s", &p1, g1, &p2, g2 );
            result = judge( *g1, *g2 );
            if( result < 0 )
                ++lose[ p1 ], ++win[ p2 ];
            else if( result > 0 )
                ++win[ p1 ], ++lose[ p2 ];
        }
        for( int i = 1; i <= player; ++i )
            if( win[ i ] + lose[ i ] )
                printf( "%.3f\n", double( win[ i ] ) / ( win[ i ] + lose[ i ] ) ) + 1e-12;
            else
                puts( "-" );
    }

	return 0;
}