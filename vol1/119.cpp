#include<iostream>
#include<map>
#include<cctype>
using namespace std;

int main()
{
    int grp, dollar, people, give;
    string send, get, name;
    bool first = true;

    while( cin >> grp )
    {
        map<string, int> man;
        string all[ grp ];
        if( !first )
            cout << endl;
        else
            first = false;
        for( int i = 0; i < grp; ++i )
        {
            cin >> all[ i ];
            cin.get();
            man[ all[ i ] ] = 0;
        }
        while( isalpha( cin.peek() ) )
        {
            cin >> send >> dollar >> people;
            if( people )
                give = dollar / people;
            for( int i = 0; i < people; ++i )
            {
                cin >> get;
                man[ get ] += give;
                man[ send ] -= give;
            }
            cin.get();
        }
        for( int i = 0; i < grp; ++i )
            cout << all[ i ] << ' ' << man[ all[ i ] ] << endl;
    }

	return 0;
}