#include<iostream>
using namespace std;
inline bool stay( int *array, int people, int week )
{
    for( int i = 0; i < week; ++i )
        if( array[ i ] >= people )
            return true;
    return false;
}

int main()
{
    int people, budget, hotel, week, bed[ 18 ][ 13 ], price[ 18 ];

    while( cin >> people >> budget >> hotel >> week )
    {
        int cost = 1000000000;
        for( int i = 0; i < hotel; ++i )
        {
            cin >> price[ i ];
            for( int j = 0; j < week; ++j )
                cin >> bed[ i ][ j ];
        }
        for( int i = 0; i < hotel; ++i )
            if( people * price[ i ] < cost && people * price[ i ] <= budget && stay( bed[ i ], people, week ) )
                cost = people * price[ i ];
        if( cost != 1000000000 )
            cout << cost << endl;
        else
            cout << "stay home\n";
    }

	return 0;
}