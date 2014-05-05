#include<iostream>
using namespace std;

int main()
{
    int act, amount = 0, dollar;
    string action;
    cin >> act;

    while( act-- )
    {
        cin >> action;
        if( action == "donate" )
        {
            cin >> dollar;
            amount += dollar;
        }
        else
            cout << amount << endl;
    }

    return 0;
}
