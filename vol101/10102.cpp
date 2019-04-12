#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node
{
public:
    int row, col;
    node( int, int );
};
node::node( int r, int c )
{
    row = r;
    col = c;
}
vector<node> one, three;
int path( int x, int y, char **field )
{
    int back = 1e9;
    for( vector<node>::iterator it = three.begin(); it != three.end(); ++it )
        back = min( back, abs( x - (*it).row )+abs( y - (*it).col ) );
    return back;
}

int main()
{
    int size;
    char **field = NULL;

    while( cin >> size )
    {
        int ans = 0;
        field = new char*[ size ];
        for( int i = 0; i < size; ++i )
            field[ i ] = new char[ size+1 ];
        for( int i = 0; i < size; ++i )
            cin >> field[ i ];

        for( int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j )
                if( field[ i ][ j ] == '1' )
                {
                    node a( i, j );
                    one.push_back( a );
                }
                else if( field[ i ][ j ] == '3' )
                {
                    node a( i, j );
                    three.push_back( a );
                }
        for( vector<node>::iterator it = one.begin(); it != one.end(); ++it )
            ans = max( ans, path( (*it).row, (*it).col, field ) );
        cout << ans << endl;

        for( int i = 0; i < size; ++i )
            delete[] field[ i ];
        delete[] field;
        one.clear();
        three.clear();
    }

    return 0;
}
