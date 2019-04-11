#include<iostream>
#include<list>
#include<algorithm>
#include<cstring>
using namespace std;
const char *map[] = { "", "qaz", "wsx", "edc", "rfvtgb" , " ", " ", "yhnujm", "ik,", "ol.", "p;/" };
bool cmp ( string a, string b )
{
    if( a.size() != b.size() )
        return a.size() > b.size();
    else
        return a < b;
}

int main()
{
    int finger, word, tmp;

    while( cin >> finger >> word )
    {
        bool handi[ 11 ] = { false }, type = true;
        string List[ word ], out[ word ];
        int in = 0;

        for( int i = 1; i <= finger; ++i )
        {
            cin >> tmp;
            handi[ tmp ] = true;
        }
        if( handi[ 5 ] ^ handi[ 6 ] )
            handi[ 5 ] = handi[ 6 ] = true;
        for( int i = 0; i < word; ++i )
            cin >> List[ i ];
        sort( List, List+word, cmp );

        for( int i = 0; i < word; ++i, type = true )
            if( !in || out[ 0 ].size() == List[ i ].size() )
                for( int m = 1; m <= 11 && type; ++m )
                    if( m == 11 )
                        out[ in++ ] = List[ i ];
                    else if( handi[ m ] )
                        for( int k = strlen( map[ m ] )-1; k >= 0 && type; --k )
                            if( strchr( List[ i ].c_str(), map[ m ][ k ] ) )
                                type = false;
        list<string> final( out, out+in );
        final.unique();
        cout << final.size() << endl;
        for( list<string>::iterator it = final.begin(); it != final.end(); ++it )
            cout << *it << endl;
    }
    return 0;
}
