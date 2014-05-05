#include<cstdio>
#include<list>
using namespace std;

int main()
{
    char in[ 100001 ];

    while ( gets( in ) )
    {
        list<char> str;
        list<char>::iterator it = str.begin();

        for ( int i = 0; in[ i ]; ++i )
            if( in[ i ] == '[' )
                it = str.begin();
            else if( in[ i ] == ']' )
                it = str.end();
            else
                str.insert( it, in[ i ] );

        for( it = str.begin(); it != str.end(); ++it )
            putchar( *it );
        putchar( '\n' );
    }

    return 0;
}
