#include<iostream>
using namespace std;

int main()
{
    char s[ 100000 ], t[ 100000 ];
    while( cin >> s >> t )
    {
        int S = 0, T = 0;
        for( ; t[ T ] && s[ S ]; ++T )
            if( s[ S ] == t[ T ] )
                ++S;
        cout << ( s[ S ]? "No" : "Yes" ) << endl;
    }

	return 0;
}