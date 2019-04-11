#include<iostream>
using namespace std;

int main()
{
    int test = 0, size;
    cin >> test;

    for( int i = 0; i < test; ++i )
    {
        char mine[ 20 ][ 20 ] = { 0 }, touch[ 20 ][ 20 ] = { 0 };
        bool bomb = false;
        cin >> size;
        if( i )
            cout << endl;

        for( int i = 1; i <= size; ++i )
            cin >> mine[ i ]+1;
        for( int i = 1; i <= size; ++i )
            cin >> touch[ i ]+1;
        for( int i = 1; i <= size && !bomb; ++i )
            for( int j = 1; j <= size && !bomb; ++j )
                if( touch[ i ][ j ] == 'x' && mine[ i ][ j ] == '*' )
                    bomb = true;

        if( bomb )
            for( int i = 1; i <= size; ++i )
            {
                for( int j = 1; j <= size; ++j )
                    if( touch[ i ][ j ] == 'x' || mine[ i ][ j ] == '*' )
                        if( mine[ i ][ j ] == '.' )
                        {
                            int out = 0;
                            for( int m = i-1; m <= i+1; ++m )
                                for( int n = j-1; n <= j+1; ++n )
                                    if( ( m != i || n != j ) && mine[ m ][ n ] == '*' )
                                        ++out;
                            cout << out;
                        }
                        else
                            cout << '*';
                    else
                        cout << '.';
                cout << endl;
            }
        else
            for( int i = 1; i <= size; ++i )
            {
                for( int j = 1; j <= size; ++j )
                    if( touch[ i ][ j ] == 'x' )
                    {
                        int out = 0;
                        for( int m = i-1; m <= i+1; ++m )
                            for( int n = j-1; n <= j+1; ++n )
                                if( ( m != i || n != j ) && mine[ m ][ n ] == '*' )
                                    ++out;
                        cout << out;
                    }
                    else
                        cout << '.';
                cout << endl;
            }
    }
    return 0;
}
