#include<iostream>
using namespace std;

int main()
{
    char *index = "01230120022455012623010202", test[ 20 ];

    while( cin >> test )
    {
        char last = '.';
        int i = -1;
        while( test[ ++i ] )
        {
            if( last != index[ test[ i ]-'A' ] && index[ test[ i ]-'A' ] != '0' )
                cout << index[ test[ i ]-'A' ];
            last = index[ test [ i ]-'A' ];
        }
        cout << endl;
    }

    return 0;
}
