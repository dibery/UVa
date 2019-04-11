#include<iostream>
#include<cstring>
using namespace std;
const char* order[] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

int main()
{
    unsigned int glass[ 3 ][ 3 ];

    while( cin >> **glass )
    {
        unsigned int move = 1 << 31, out, tmp;
        for( int i = 1; i < 9; ++i )
            cin >> glass[ i/3 ][ i%3 ];
        for( int i = 0; i < 6; ++i )
        {
            tmp = 0;
            for( int j = 0; j < 3; ++j )
            {
                if( order[ i ][ j ] == 'B' )
                    for( int k = 0; k < 3; ++k )
                        if( k != j )
                            tmp += glass[ k ][ 0 ];
                        else;
                else if( order[ i ][ j ] == 'C' )
                    for( int k = 0; k < 3; ++k )
                        if( k != j )
                            tmp += glass[ k ][ 2 ];
                        else;
                else
                    for( int k = 0; k < 3; ++k )
                        if( k != j )
                            tmp += glass[ k ][ 1 ];
            }
            if( tmp < move )
            {
                move = tmp;
                out = i;
            }
        }
        cout << order[ out ] << ' ' << move << endl;
    }
    return 0;
}
