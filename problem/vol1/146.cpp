#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    char str[ 51 ];

    while( cin >> str && *str != '#' )
        cout << ( next_permutation( str, str+strlen( str ) )? str : "No Successor" ) << endl;

    return 0;
}
