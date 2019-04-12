#include<iostream>
#include<map>
#include<list>
using namespace std;

int main()
{
    int line;
    char tmp[ 80 ];
    string nation;
    map<string, int> love;
    list<string> name;
    cin >> line;

    for( int i = 0; i < line; ++i )
    {
        cin >> nation;
        cin.getline( tmp, 80 );
        ++love[ nation ];
        name.push_back( nation );
    }
    name.sort();
    name.unique();
    for( list<string>::iterator it = name.begin(); it != name.end(); ++it )
        cout << *it << ' ' << love[ *it ] << endl;

    return 0;
}
