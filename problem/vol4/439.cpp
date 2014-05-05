#include<iostream>
#include<queue>
using namespace std;

int main()
{
    string begin, end;
    int from, to, jumpx[ 8 ] = { 10, 20, 20, 10, -10, -20, -20, -10 }, jumpy[ 8 ] = { 2, 1, -1, -2, -2, -1, 1, 2 };

    while( cin >> begin >> end )
    {
        int dist[ 8 ][ 8 ] = { 0 };
        from = ( begin[ 0 ]-'a' ) * 10 + begin[ 1 ]-'1';
        to = ( end[ 0 ]-'a' ) * 10 + end[ 1 ]-'1';
        queue<int> knight;
        knight.push( from );
        dist[ from / 10 ][ from % 10 ] = 1;
        while( !dist[ to / 10 ][ to % 10 ] )
        {
            for( int i = 0; i < 8; ++i )
            {
                int next = knight.front() + jumpx[ i ] + jumpy[ i ];
                if( next % 10 >= 8 || next > 77 || next < 0 )
                    continue;
                if( !dist[ next / 10 ][ next % 10 ] )
                    dist[ next / 10 ][ next % 10 ] = dist[ knight.front() / 10 ][ knight.front() % 10 ] + 1;
                knight.push( next );
            }
            knight.pop();
        }
        cout << "To get from " << begin << " to " << end << " takes " << dist[ to / 10 ][ to % 10 ]-1 << " knight moves.\n";
    }

    return 0;
}
