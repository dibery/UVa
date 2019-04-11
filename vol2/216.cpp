#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
using namespace std;
inline int squ( int a ) { return a*a; }
int num, t = 0;
double sale( int *order, double dist[ 8 ][ 8 ] )
{
    double ans = 0;
    for( int i = 0; i < num-1; ++i )
        ans += dist[ order[ i ] ][ order[ i+1 ] ];
    return ans;
}

int main()
{
    while( cin >> num && num )
    {
        int x[ num ], y[ num ], order[] = { 0, 1, 2, 3, 4, 5, 6, 7 }, call[ num ];
        double dist[ 8 ][ 8 ], ans = INT_MAX, tmp;
        for( int i = 0; i < num; ++i )
            cin >> x[ i ] >> y[ i ];
        for( int i = 0; i < num; ++i )
            for( int j = 0; j < num; ++j )
                dist[ i ][ j ] = i == j? INT_MAX : 16 + sqrt( squ( x[ i ]-x[ j ] ) + squ( y[ i ]-y[ j ] ) );
        do
            if( ans > ( tmp = sale( order, dist ) ) )
            {
                ans = tmp;
                for( int i = 0; i < num; ++i )
                    call[ i ] = order[ i ];
            }
        while( next_permutation( order, order+num ) );
        cout << "**********************************************************\nNetwork #" << ++t << endl;
        for( int i = 0; i < num-1; ++i )
            printf( "Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", x[ call[ i ] ], y[ call[ i ] ], x[ call[ i+1 ] ], y[ call[ i+1 ] ], dist[ call[ i ] ][ call[ i+1 ] ] );
            printf( "Number of feet of cable required is %.2f.\n", ans );
    }

	return 0;
}