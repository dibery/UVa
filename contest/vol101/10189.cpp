#include<iostream>
using namespace std;

int main()
{
    int x, y, test = 0;

    while( cin >> x >> y && ( x || y ) )
    {
        char field[ 201 ] = { 0 };
        int mine[ 202 ][ 202 ] = { 0 };
        if( test )
            cout << endl;
        for( int i = 1; i <= x; ++i )
        {
            cin >> field+1;
            for( int j = 1; j <= y; ++j )
                if( field[ j ] == '*' )
                {
                    for( int m = i-1; m <= i+1; ++m )
                        for( int n = j-1; n <= j+1; ++n )
                            ++mine[ m ][ n ];
                    mine[ i ][ j ] = -1000;
                }
        }
        cout << "Field #" << ++test << ":\n";
        for( int i = 1; i <= x; ++i )
            for( int j = 1; j <= y; ++j )
                if( j == y )
                    if( mine[ i ][ j ] < 0 )
                        cout << '*' << endl;
                    else
                        cout << mine[ i ][ j ] << endl;
                else if( mine[ i ][ j ] < 0 )
                    cout << '*';
                else
                    cout << mine[ i ][ j ];
    }
    return 0;
}
