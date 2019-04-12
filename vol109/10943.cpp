#include<iostream>
#define H( x, y ) C( x+y-1, x )
using namespace std;
int C( int m, int n )
{
    int factor[ 200 ] = { 0 }, back = 1;
    for( int i = n+1, j = i; i <= m; j = ++i )
        for( int k = 2; j > 1; ++k )
            while( j % k == 0 )
            {
                ++factor[ k ];
                j /= k;
            }
    for( int i = 2, j = i; i <= m-n; j = ++i )
        for( int k = 2; j > 1; ++k )
            while( j % k == 0 )
            {
                --factor[ k ];
                j /= k;
            }
    for( int i = 2; i <= 199; ++i )
        while( factor[ i ] )
        {
            back *= i;
            --factor[ i ];
            back %= 1000000;
        }
    return back;
}

int main()
{
    int m, n;

    while( cin >> m >> n && m )
        cout << H( m, n ) << endl;

    return 0;
}
