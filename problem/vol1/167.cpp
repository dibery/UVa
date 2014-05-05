#include<cstdio>
#include<algorithm>
using namespace std;
void queen( int board[ 8 ][ 8 ], int R, int C, bool *row, bool *up, bool *down, int score, int &Max )
{
    if( C == 8 )
    {
        Max = max( Max, score );
        return;
    }
    if( row[ R ] || up[ R - C + 7 ] || down[ R + C ] )
        return;
    row[ R ] = up[ R - C + 7 ] = down[ R + C ] = true;
    for( int i = 0; i < 8; ++i )
        queen( board, i, C+1, row, up, down, score+board[ R ][ C ], Max );
    row[ R ] = up[ R - C + 7 ] = down[ R + C ] = false;
}

int main()
{
    int t, board[ 8 ][ 8 ];
    scanf( "%d", &t );

    while( t-- )
    {
        bool row[ 8 ] = { false }, col[ 8 ] = { false }, up[ 15 ] = { false }, down[ 15 ] = { false };
        int score = 0, Max = 0;
        for( int i = 0; i < 64; ++i )
            scanf( "%d", board[ i/8 ] + i%8 );
        for( int i = 0; i < 8; ++i )
            queen( board, i, 0, row, up, down, 0, Max );   //put in each col
        printf( "%5d\n", Max );
    }

    return 0;
}
