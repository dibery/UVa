#include<cstdio>
#include<cstring>

int main()
{
    int test, people, send, dice, target[ 101 ], from, to, point, game_end = 0, now;
    char tmp[ 2 ];
    scanf( "%d", &test );

    for( int z = 0; z < test; ++z )
    {
        game_end = 0;
        scanf( "%d %d %d", &people, &send, &dice );
        int *player = new int[ people ];
        for( int i = 0; i < people; ++i )
            player[ i ] = 1;
        memset( target, -1, sizeof( target ) );
        for( int i = 0; i < send; ++i )
        {
            scanf( "%d %d", &from, &to );
            target[ from ] = to;
        }
        for( int i = 0; i < dice; ++i )
            if( game_end )
                scanf( "%s", tmp );
            else
            {
                now = i % people;
                scanf( "%d", &point );
                player[ now ] += point;
                if( player[ now ] < 100 && target[ player[ now ] ] != -1 )
                    player[ now ] = target[ player[ now ] ];
                if( player[ now ] >= 100 )
                    game_end = 1;
            }
        for( int i = 0; i < people; ++i )
            printf( "Position of player %d is %d.\n", i+1, player[ i ] );
        delete[] player;
    }
    return 0;
}
