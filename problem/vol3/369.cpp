#include<iostream>
using namespace std;
unsigned long long int take( int n, int m )
{
    int factor[ 100 ] = { 0 };
    unsigned long long int back = 1;

    for( int i = 2; i <= n; ++i )
        for( int j = i; j != 1; )
            for( int k = 2; k <= j; ++k )
                while( j % k == 0 )
                {
                    ++factor[ k ];
                    j /= k;
                }
    for( int i = 2; i <= m; ++i )
        for( int j = i; j != 1; )
            for( int k = 2; k <= j; ++k )
                while( j % k == 0 )
                {
                    --factor[ k ];
                    j /= k;
                }
    for( int i = 2; i <= n-m; ++i )
        for( int j = i; j != 1; )
            for( int k = 2; k <= j; ++k )
                while( j % k == 0 )
                {
                    --factor[ k ];
                    j /= k;
                }
    for( int i = 2; i < 100; ++i )
        if( factor[ i ] )
            while( factor[ i ]-- )
                back *= i;
    return back;
}

int main()
{
    int n, m;
    cout.precision( 50 );

    while( cin >> n >> m && n && m )
        cout << n << " things taken " << m << " at a time is " << take( n, m ) << " exactly." << endl;
    return 0;
}
