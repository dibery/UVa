#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
inline int square( int a ) { return a*a; }
inline bool pand( int i, int j, int width, char array[ 200 ][ 200 ] ) { return array[ i ][ j ] == array[ j ][ i ] && array[ i ][ j ] == array[ width-1-j ][ width-1-i ] && array[ i ][ j ] == array[ width-1-i ][ width-1-j ]; }

int main()
{
    char str[ 20000 ], op[ 20000 ];
    int test = 0, width;
    gets( str );

    while( gets( str ) )
    {
        int len = -1;
        char array[ 200 ][ 200 ] = { 0 };
        for( int k = 0; str[ k ]; ++k )
            if( isalpha( str[ k ] ) )
                op[ ++len ] = str[ k ];
        if( square( width = sqrt( double( len+1 ) ) ) != len+1 )
        {
            cout << "Case #" << ++test << ":\nNo magic :(\n";
            continue;
        }
        else
        {
            for( int k = 0; k < width; ++k )
                strncpy( array[ k ], op+k*width, width );
            for( int i = 0; i < (width+1)>>1; ++i )
                for( int j = i; j < width-i; ++j )
                    if( !pand( i, j, width, array ) )
                    {
                        cout << "Case #" << ++test << ":\nNo magic :(\n";
                        goto end;
                    }
            cout << "Case #" << ++test << ":\n" << width << endl;
end:
            ++len;
        }
    }

    return 0;
}
