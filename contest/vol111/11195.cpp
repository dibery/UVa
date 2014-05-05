#include<cstdio>
void bt( int *brd, int size, int now, int col, int slope_up, int slope_down, int &sol )
{
    if( now == size )
    {
        ++sol;
        return;
    }
    for( int all_pos = brd[ now ] & col & ( slope_down >> size-now-1 ) & ( slope_up >> now ), next; all_pos; all_pos ^= next )
    {
        next = all_pos & -all_pos;
        bt( brd, size, now+1, col ^ next, slope_up ^ ( next << now ), slope_down ^ ( next << size - now - 1 ), sol );
    }
}

int main()
{
    int t = 0, size;
    char input[ 20 ];

    while( scanf( "%d", &size ) && size )
    {
        int board[ 14 ] = { 0 }, sol = 0;
        for( int i = 0; i < size; board[ i++ ] ^= ( 1 << size ) - 1 )
        {
            scanf( "%s", input );
            for( int j = 0; j < size; ++j )
                if( input[ j ] == '*' )
                    board[ i ] ^= 1 << size-j-1;
        }
        bt( board, size, 0, ( 1 << size ) - 1, ( 1 << size*2 - 1 ) - 1, ( 1 << size*2 - 1 ) - 1, sol );
        printf( "Case %d: %d\n", ++t, sol );
    }

    return 0;
}