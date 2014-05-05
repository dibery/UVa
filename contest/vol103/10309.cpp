#include<cstdio>
#include<cstring>
#include<algorithm>
const char odd = 'O', even = '#';
bool press_even( bool press[ 10 ][ 10 ], int i, int j )
{
    int back = 0;
    for( int m = i-1; m <= i+1; ++m )
        for( int n = j-1; n <= j+1; ++n )
            back += m >= 0 && m < 10 && n >= 0 && n < 10 && ( m == i || n == j ) && press[ m ][ n ];
    return back % 2 == 0;
}
int Fill( int first, char bulb[ 10 ][ 11 ] )
{
    bool press[ 10 ][ 10 ] = { false };
    int back = 0;
    for( int i = 0; i < 10; ++i )
        press[ 0 ][ i ] = first & 1, first >>= 1;
    for( int i = 1; i < 10; ++i )
        for( int j = 0; j < 10; ++j )
            press[ i ][ j ] = press_even( press, i-1, j ) ^ bulb[ i-1 ][ j ] == even;
    for( int i = 0; i < 10; ++i )
        if( press_even( press, 9, i ) ^ bulb[ 9 ][ i ] == even )
            return 101;
    for( int i = 0; i < 10; ++i )
        for( int j = 0; j < 10; ++j )
            back += press[ i ][ j ];
    return back;
}

int main()
{
    char name[ 100 ], bulb[ 10 ][ 11 ];

    while( gets( name ) && strcmp( name, "end" ) )
    {
        int ans = 101;
        for( int i = 0; i < 10; ++i )
            gets( bulb[ i ] );
        for( int i = 0; i < 1024; ++i )
            ans = std::min( Fill( i, bulb ), ans );
        printf( "%s %d\n", name, ans == 101? -1 : ans );
    }

    return 0;
}