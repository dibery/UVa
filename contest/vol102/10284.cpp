#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;
const char none = 0, attack = '*';
void process( char board[ 8 ][ 8 ] );

int main()
{
    char board[ 8 ][ 8 ], in;
    int index = 0;
    memset( board, none, sizeof( board ) );

    while( scanf( "%c", &in ) != EOF )
    {
        if( isdigit( in ) )
            index += in - '0';
        else if( isalpha( in ) )
            board[ index / 8 ][ (index++) % 8 ] = in;
        if( in == '\n' )
        {
            process( board );
            index = 0;
            memset( board, none, sizeof( board ) );
        }
    }
    process( board );
    return 0;
}
void process( char board[ 8 ][ 8 ] )
{
    int ans = 0;
    for( int i = 0; i < 8; ++i )
        for( int j = 0; j < 8; ++j )
        {
            if( board[ i ][ j ] == 'k' || board[ i ][ j ] == 'K' )
                for( int m = i-1; m <= i+1; ++m )
                    for( int n = j-1; n <= j+1; ++n )
                        if( m >= 0 && m < 8 && n >= 0 && n < 8 )
                            board[ m ][ n ] = board[ m ][ n ] == none? attack : board[ m ][ n ];
            if( board[ i ][ j ] == 'p' )
                if( i == 7 );
                else if( j == 0 )
                    board[ i+1 ][ j+1 ] = board[ i+1 ][ j+1 ] == none? attack : board[ i+1 ][ j+1 ];
                else if( j == 7 )
                    board[ i+1 ][ j-1 ] = board[ i+1 ][ j-1 ] == none? attack : board[ i+1 ][ j-1 ];
                else
                {
                    board[ i+1 ][ j+1 ] = board[ i+1 ][ j+1 ] == none? attack : board[ i+1 ][ j+1 ];
                    board[ i+1 ][ j-1 ] = board[ i+1 ][ j-1 ] == none? attack : board[ i+1 ][ j-1 ];
                }
            if( board[ i ][ j ] == 'P' )
                if( i == 0 );
                else if( j == 0 )
                    board[ i-1 ][ j+1 ] = board[ i-1 ][ j+1 ] == none? attack : board[ i-1 ][ j+1 ];
                else if( j == 7 )
                    board[ i-1 ][ j-1 ] = board[ i-1 ][ j-1 ] == none? attack : board[ i-1 ][ j-1 ];
                else
                {
                    board[ i-1 ][ j+1 ] = board[ i-1 ][ j+1 ] == none? attack : board[ i-1 ][ j+1 ];
                    board[ i-1 ][ j-1 ] = board[ i-1 ][ j-1 ] == none? attack : board[ i-1 ][ j-1 ];
                }
            if( board[ i ][ j ] == 'r' || board[ i ][ j ] == 'R' || board[ i ][ j ] == 'q' || board[ i ][ j ] == 'Q' )
            {
                for( int k = j+1; k < 8 && ( board[ i ][ k ] == none || board[ i ][ k ] == attack ); ++k )
                    board[ i ][ k ] = attack;
                for( int k = j-1; k >= 0 && ( board[ i ][ k ] == none || board[ i ][ k ] == attack ); --k )
                    board[ i ][ k ] = attack;
                for( int k = i-1; k >= 0 && ( board[ k ][ j ] == none || board[ k ][ j ] == attack ); --k )
                    board[ k ][ j ] = attack;
                for( int k = i+1; k < 8 && ( board[ k ][ j ] == none || board[ k ][ j ] == attack ); ++k )
                    board[ k ][ j ] = attack;
            }
            if( board[ i ][ j ] == 'n' || board[ i ][ j ] == 'N' )
            {
                if( i <= 5 && j <= 6 )
                    board[ i+2 ][ j+1 ] = board[ i+2 ][ j+1 ] == none? attack : board[ i+2 ][ j+1 ];
                if( i <= 6 && j <= 5 )
                    board[ i+1 ][ j+2 ] = board[ i+1 ][ j+2 ] == none? attack : board[ i+1 ][ j+2 ];
                if( i >= 1 && j <= 5 )
                    board[ i-1 ][ j+2 ] = board[ i-1 ][ j+2 ] == none? attack : board[ i-1 ][ j+2 ];
                if( i >= 2 && j <= 6 )
                    board[ i-2 ][ j+1 ] = board[ i-2 ][ j+1 ] == none? attack : board[ i-2 ][ j+1 ];
                if( i >= 2 && j >= 1 )
                    board[ i-2 ][ j-1 ] = board[ i-2 ][ j-1 ] == none? attack : board[ i-2 ][ j-1 ];
                if( i >= 1 && j >= 2 )
                    board[ i-1 ][ j-2 ] = board[ i-1 ][ j-2 ] == none? attack : board[ i-1 ][ j-2 ];
                if( i <= 6 && j >= 2 )
                    board[ i+1 ][ j-2 ] = board[ i+1 ][ j-2 ] == none? attack : board[ i+1 ][ j-2 ];
                if( i <= 5 && j >= 1 )
                    board[ i+2 ][ j-1 ] = board[ i+2 ][ j-1 ] == none? attack : board[ i+2 ][ j-1 ];
            }
            if( board[ i ][ j ] == 'b' || board[ i ][ j ] == 'B' || board[ i ][ j ] == 'q' || board[ i ][ j ] == 'Q' )
            {
                for( int m = i+1, n = j+1; m < 8 && n < 8 && ( board[ m ][ n ] == none || board[ m ][ n ] == attack ); ++m, ++n )
                    board[ m ][ n ] = board[ m ][ n ] == none? attack : board[ m ][ n ];
                for( int m = i+1, n = j-1; m < 8 && n >= 0 && ( board[ m ][ n ] == none || board[ m ][ n ] == attack ); ++m, --n )
                    board[ m ][ n ] = board[ m ][ n ] == none? attack : board[ m ][ n ];
                for( int m = i-1, n = j-1; m >= 0 && n >= 0 && ( board[ m ][ n ] == none || board[ m ][ n ] == attack ); --m, --n )
                    board[ m ][ n ] = board[ m ][ n ] == none? attack : board[ m ][ n ];
                for( int m = i-1, n = j+1; m >= 0 && n < 8 && ( board[ m ][ n ] == none || board[ m ][ n ] == attack ); --m, ++n )
                    board[ m ][ n ] = board[ m ][ n ] == none? attack : board[ m ][ n ];
            }
        }
    for( int i = 0; i < 8; ++i )
        for( int j = 0; j < 8; ++j )
            if( board[ i ][ j ] == none )
                ++ans;
    printf( "%d\n", ans );
}
