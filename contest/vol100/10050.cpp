#include<iostream>
using namespace std;
inline bool strike( int *mod, int day, int size )
{
    for( int i = 0; i < size; ++i )
        if( day % mod[ i ] == 0 )
            return true;
    return false;
}

int main()
{
    int test, day, party, mod[ 100 ], lose = 0;
    cin >> test;

    while( test-- )
    {
        lose = 0;
        cin >> day >> party;
        for( int i = 0; i < party; ++i )
            cin >> mod[ i ];
        for( int i = 1; i <= day; ++i )
            if( i % 7 != 0 && i % 7 != 6 && strike( mod, i, party ) )
                ++lose;
        cout << lose << endl;
    }

	return 0;
}