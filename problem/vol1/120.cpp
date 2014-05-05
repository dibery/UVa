#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool done( int *begin, int *end )
{
    for( ++begin; begin != end; ++begin )
        if( *begin < *( begin-1 ) )
            return false;
    return true;
}

int main()
{
    int pan[ 30 ] = { 0 }, now = 0;
    priority_queue<int> all;

    while( cin >> pan[ now++ ] )
    {
        if( cin.peek() == ' ' )
            cin.get(), all.push( pan[ now-1 ] );
        else
        {
            all.push( pan[ now-1 ] );
            for( int i = 0; i < now; ++i )
                cout << pan[ i ] << ( i == now-1? '\n' : ' ' );
            for( int i = 1; i <= now && !done( pan, pan+now ); ++i )
            {
                int *pos = find( pan, pan+now, all.top() );
                cout << pan + now - pos << ' ' << i << ' ';
                reverse( pan, pos + 1 );
                reverse( pan, pan + (now - i + 1) );
                all.pop();
            }
            cout << 0 << endl;
            if( cin.peek() != '\n' )
                break;
            while( !all.empty() )
                all.pop();
            now = 0;
        }
    }

	return 0;
}