#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    long long int test, fact[ 21 ] = { 1 };
    cin >> test;
    for( int i = 1; i < 21; ++i )
        fact[ i ] = i * fact[ i-1 ];

    for( int i = 1; i <= test; ++i )
    {
        string str;
        long long int permu;
        cin >> str >> permu;
        int len = str.size();
        sort( str.begin(), str.end() );

        for( int k = len-1; k >= 0; --k )
        {
            cout << str[ permu/fact[ k ] ];
            str.erase( permu/fact[ k ], 1 );
            permu %= fact[ k ];
        }
        cout << endl;
    }
}
