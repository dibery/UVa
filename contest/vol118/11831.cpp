#include<iostream>
#define robot field[i][j]
using namespace std;
const int up = 1, down = 3, Left = 0, Right = 2;
const char sticker = '*', pillar = '#', normal = '.', toLeft = 'E', toRight = 'D', forward = 'F';
inline int turnRight( char &a )
{
    if( a == 3 )
        return a = 0;
    else
        return ++a;
}
inline int turnLeft( char &a )
{
    if( a == 0 )
        return a = 3;
    else
        return --a;
}

int main()
{
    int row, col, ins;

    while( cin >> row >> col >> ins && row )
    {
        char field[ row ][ col+1 ], move[ ins+1 ];
        int i = 0, j = 0, get = 0;
        bool found = false;
        for( int i = 0; i < row; ++i )
            cin >> field[ i ];
        cin >> move;
        for( i = 0; i < row && !found; ++i )
            for( j = 0; j < col && !found; ++j )
                if( field[ i ][ j ] == 'N' || field[ i ][ j ] == 'L' || field[ i ][ j ] == 'S' || field[ i ][ j ] == 'O' )
                    found = true;
        --i;
        --j;
        if( robot == 'N' )
            robot = up;
        else if( robot == 'S' )
            robot = down;
        else if( robot == 'L' )
            robot = Right;
        else if( robot == 'O' )
            robot = Left;
        for( int m = 0; move[ m ]; ++m )
        {
            if( move[ m ] == toLeft )
                turnLeft( robot );
            else if( move[ m ] == toRight )
                turnRight( robot );
            else//
                if( robot == up )
                    if( i == 0 || field[ i-1 ][ j ] == pillar );
                    else if( field[ i-1 ][ j ] == normal )
                    {
                        field[ i-1 ][ j ] = robot;
                        field[ i-- ][ j ] = normal;
                    }
                    else
                    {
                        field[ i-1 ][ j ] = robot;
                        field[ i-- ][ j ] = normal;
                        ++get;
                    }
                else if( robot == down )
                    if( i == row-1 || field[ i+1 ][ j ] == pillar );
                    else if( field[ i+1 ][ j ] == normal )
                    {
                        field[ i+1 ][ j ] = robot;
                        field[ i++ ][ j ] = normal;
                    }
                    else
                    {
                        field[ i+1 ][ j ] = robot;
                        field[ i++ ][ j ] = normal;
                        ++get;
                    }
                else if( robot == Left )
                    if( j == 0 || field[ i ][ j-1 ] == pillar );
                    else if( field[ i ][ j-1 ] == normal )
                    {
                        field[ i ][ j-1 ] = robot;
                        field[ i ][ j-- ] = normal;
                    }
                    else
                    {
                        field[ i ][ j-1 ] = robot;
                        field[ i ][ j-- ] = normal;
                        ++get;
                    }
                else//
                    if( j == col-1 || field[ i ][ j+1 ] == pillar );
                    else if( field[ i ][ j+1 ] == normal )
                    {
                        field[ i ][ j+1 ] = robot;
                        field[ i ][ j++ ] = normal;
                    }
                    else
                    {
                        field[ i ][ j+1 ] = robot;
                        field[ i ][ j++ ] = normal;
                        ++get;
                    }
        }
        cout << get << endl;
    }

    return 0;
}
