#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int in;
    char ans[ 10012 ][ 46 ] = { 0 }, d[ 10012 ][ 43 ] = { 0 }, two[ 142 ][ 43 ] = { 1 };

    for( int i = 1; i < 142; ++i )
    {
        for( int j = 0; j < 43; ++j )
            two[ i ][ j ] = two[ i-1 ][ j ] << 1;
        for( int j = 0; j < 43; ++j )
            if( two[ i ][ j ] > 9 )
            {
                two[ i ][ j+1 ] += two[ i ][ j ] / 10;
                two[ i ][ j ] %= 10;
            }
    }   // power of 2: 2^0 ~ 2^141

    for( int i = 0, key = 1; i <= 141; ++i )
        for( int k = 0; k <= i; ++k, ++key )
            for( int m = 0; m < 43; ++m )
                d[ key ][ m ] = two[ i ][ m ];  //transfer the difference of each item
    memset( ans, 0, sizeof( ans ) );

    for( int i = 1; i <= 10000; ++i )
    {
        for( int k = 0; k < 46; ++k )
            ans[ i ][ k ] = ans[ i-1 ][ k ];
        for( int k = 0; k < 43; ++k )
            ans[ i ][ k ] += d[ i ][ k ];
        for( int k = 0; k < 46; ++k )
            if( ans[ i ][ k ] > 9 )
            {
                ans[ i ][ k+1 ] += ans[ i ][ k ] / 10;
                ans[ i ][ k ] %= 10;
            }
    }   //the answer table

    **ans = '0';
    for( int k = 1, i = 46; k <= 10000; ++k, i = 46 )
    {
        while( !ans[ k ][ --i ] );
        for( ; i >= 0; --i )
            ans[ k ][ i ] += '0';
        std::reverse( ans[ k ], ans[ k ]+strlen( ans[ k ] ) );
    }

    while( cin >> in )
        cout << ans[ in ] << endl;

    return 0;
}
