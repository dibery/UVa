#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
bool Strcmp( char *a, char *b )
{
    int len = strlen( a );
    char *alpha = "A   3  HIL JM O   2TUVWXY5", *num = "01SE Z  8 ";
    for( int i = 0; i < len; ++i )
        if( isalpha( b[ i ] ) )
            if( a[ i ] != alpha[ b[ i ]-'A' ] )
                return false;
            else
                continue;
        else//
            if( a[ i ] != num[ b[ i ]-'0' ] )
                return false;
            else
                continue;
    return true;
}
bool Pand( char *str )
{
    char *tmp = strdup( str );
    reverse( tmp, tmp+strlen( tmp ) );
    return strcmp( tmp, str ) == 0;
}
bool Mirr( char *str )
{
    char *tmp = strdup( str );
    reverse( tmp, tmp+strlen( tmp ) );
    return Strcmp( tmp, str );
}

int main()
{
    char str[ 21 ];

    while( cin >> str )
    {
        bool pand = Pand( str ), mirr = Mirr( str );
        if( pand )
            if( mirr )
                cout << str << " -- is a mirrored palindrome.\n\n";
            else
                cout << str << " -- is a regular palindrome.\n\n";
        else//
            if( mirr )
                cout << str << " -- is a mirrored string.\n\n";
            else
                cout << str << " -- is not a palindrome.\n\n";
    }

    return 0;
}
