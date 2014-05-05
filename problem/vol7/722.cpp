#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int size = 0;
char field[ 200 ][ 200 ], land = '1', water = '0', visit[ 200 ][ 200 ];
int row, col, test, x, y;
void DFS( int x, int y )
{
    visit[ x ][ y ] = 1;
    ++size;
    //cout<<x<<' '<<y<<'?'<<endl;

    for( int i = x-1; i <= x+1; ++i )
        for( int j = y-1; j <= y+1; ++j )
            if( (i == x) ^ (j == y) )
                if( field[ i ][ j ] == water && visit[ i ][ j ] == 0 )
                    DFS( i, j );
}

int main()
{
    cin >> test;

    while( test-- )
    {
        for( int i = 0; i < 200; ++i )
            for( int j = 0; j < 200; ++j )
                visit[ i ][ j ] = field[ i ][ j ] = 0;
        for( int i = 0; i < 200; ++i )
            field[ i ][ 0 ] = land;
        int line = 1;
        cin >> x >> y;
        //cout<<x<<' '<<y<<endl;
        cin.get();
        //cout << (char)cin.peek() << '!' << endl;
        while( isdigit( cin.peek() ) )
        {
            cin >> field[ (line++) ]+1;
            cin.get();
        }
        row = line;
        col = strlen( &field[ 1 ][ 1 ] );
        for( int i = 1; i < row; ++i )
            field[ i ][ 0 ] = field[ i ][ col+1 ] = land;
        //cout<<row<<' '<<col<<'#'<<endl;
        for( int i = 0; i <= col+1; ++i )
            field[ 0 ][ i ] = field[ row ][ i ] = land;
//        for( int i = 0; i <= row; ++i )
//            cout <<"in:"<< field[ i ]<<endl;
        DFS( x, y );
        cout << size << endl;
        if( test )
            cout << endl;
        size = 0;
    }
}
