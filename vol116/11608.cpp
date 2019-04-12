#include<iostream>
using namespace std;

int main()
{
    int add[ 12 ], use[ 12 ], stock, Case = 0;

    while( cin >> stock && stock >= 0 )
    {
        for( int i = 0; i < 12; ++i )
            cin >> add[ i ];
        for( int i = 0; i < 12; ++i )
            cin >> use[ i ];
        cout << "Case " << ++Case << ":\n";
        for( int i = 0; i < 12; ++i )
        {
            if( stock >= use[ i ] )
            {
                stock -= use[ i ];
                cout << "No problem! :D\n";
            }
            else
                cout << "No problem. :(\n";
            stock += add[ i ];
        }
    }
    return 0;
}
