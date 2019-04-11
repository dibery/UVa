#include<iostream>
using namespace std;

int main()
{
    int test, sum, diff;
    cin >> test;

    while( test-- )
    {
        cin >> sum >> diff;

        if( sum < diff || ( sum+diff ) % 2 == 1 )
            cout << "impossible\n";
        else
            cout << ( sum+diff ) / 2 << ' ' << ( sum-diff ) / 2 <<endl;
    }
    return 0;
}
