#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
struct girl
{
    int play_day, envy, id;
};
bool comp( girl a, girl b )
{
    return ( a.envy * b.play_day > b.envy * a.play_day );
}

int main()
{
    int test_data;
    cin >> test_data;

    for( int i = 1; i <= test_data; i++ )
    {
        int totalgirls, the_envy = LONG_MAX, idle_days = 0, min_envy = LONG_MAX;
        cin >> totalgirls;
        girl allgirl[ totalgirls ];
        int best[ totalgirls ];

        int sorting[ totalgirls ];
        for( int j = 1; j <= totalgirls; j++ )
            sorting[ j-1 ] = j;

        for( int j = 0; j < totalgirls; j++ )
        {
            cin >> allgirl[ j ].play_day >> allgirl[ j ].envy;
            allgirl[ j ].id = j+1;
        }

        stable_sort( allgirl, allgirl+totalgirls, comp );
        for( int i = 0; i < totalgirls; i++ )
            cout << allgirl[ i ].id << ( i != totalgirls-1? " " : "\n" );
        if( i != test_data )
            cout << endl;
    }

    return 0;
}
