#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int event, order[ 20 ] = { 0 }, ans[ 20 ] = { 0 }, lis[ 20 ], tmp;
    cin >> event;

    for( int i = 0; i < event; ++i )
        cin >> order[ i ];

    while( cin >> tmp )
    {
        int score = 0;
        for( int i = 0; i < 20; ++i )
            lis[ i ] = 1;
        ans[ tmp ] = 0;
        for( int i = 1; i < event; ++i )
        {
            cin >> tmp;
            ans[ tmp ] = i;
        }
        for( int i = event; i; --i )
            for( int j = i+1; j <= event; ++j )
                if( order[ ans[ j ] ] > order[ ans[ i ] ] )
                    lis[ i ] = max( lis[ j ]+1, lis[ i ] );
        for( int i = 0; i < event; ++i )
            score = max( score, lis[ i ] );
        cout << score << endl;
    }
    return 0;
}
