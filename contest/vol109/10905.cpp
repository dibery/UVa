#include<iostream>
#include<algorithm>
using namespace std;
bool cmp( string a, string b ) { return a+b > b+a; }

int main()
{
    int size;
    string str[ 50 ];

    while( cin >> size && size )
    {
        for( int i = 0; i < size; ++i )
            cin >> str[ i ];
        sort( str, str+size, cmp );
        for( int i = 0; i < size; ++i )
            cout << str[ i ];
        cout << endl;
    }
    return 0;
}
