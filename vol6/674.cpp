#include<iostream>
using namespace std;
int op( int, int, int*, int[ 7490 ][ 6 ] );

int main()
{
    int money, sol[ 7490 ][ 6 ] = { 1 }, val[ 5 ] = { 1, 5, 10, 25, 50 };

    for( int i = 1; i <= 7489; ++i )
        sol[ i ][ 0 ] = 1;
    for( int i = 1; i <= 7489; ++i )
        for( int j = 1; j < 5; j++ )
            sol[ i ][ j ] = op( i, j, val, sol );

    for( int i = 0; i <= 7489; ++i )
        for( int j = 0; j < 5; ++j )
            sol[ i ][ 5 ] += sol[ i ][ j ];

    while( cin >> money )
        cout << sol[ money ][ 5 ] << endl;
    return 0;
}

int op( int money, int index, int *value, int ans[ 7490 ][ 6 ] )
{
    int back = 0;
    if( money < value[ index ] )
        return 0;
    for( int tmp = money - value[ index ]; tmp >= 0; tmp -= value[ index ] )
        for( int j = index-1; j >= 0; --j )
            back += ans[ tmp ][ j ];
    return back;
}
