#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char in[ 1000 ];
    int test;
    cin >> test;

    while( test-- )
    {
        cin >> in;
        if( !strcmp( in, "1" ) || !strcmp( in, "4" ) || !strcmp( in, "78" ) )
            cout << '+' << endl;
        else if( !strcmp( in+strlen( in )-2, "35" ) )
            cout << '-' << endl;
        else if( *in == '9' )
            cout << '*' << endl;
        else
            cout << '?' << endl;
    }
    return 0;
}
