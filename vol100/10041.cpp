#include<iostream>
#include<algorithm>
using namespace std;
inline int abs( int a ) { return ( a < 0? -a : a ); }

int main()
{
    int test, num, max, min, place[ 500 ], median, dist;
    cin >> test;

    while( test-- )
    {
        dist = 0;
        cin >> num;
        for( int i = 0; i < num; ++i )
            cin >> place[ i ];
        sort( place, place+num );
        if( num % 2 == 1 )
            median = place[ num >> 1 ];
        else
            median = ( place[ num >> 1 ] + place[ ( num >> 1 ) - 1 ] ) / 2;
        for( int i = 0; i < num; ++i )
            dist += abs( median - place[ i ] );
        cout << dist << endl;
    }

    return 0;
}
