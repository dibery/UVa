#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
#include<cctype>
using namespace std;
char in[ 90 ], ori[ 1000 ][ 90 ] = { 0 }, out[ 90 ];
int i = -1;
list<char*> str, cp;
int mystrcmp( char *a, char *b )
{
    for( int i = 0; a[ i ] || b[ i ]; ++i )
        if( tolower( a[ i ] ) != tolower( b[ i ] ) )
            return a[ i ] - b[ i ];
    return 0;
}
bool Ananagrams( char *word )
{
    for( list<char*>::iterator it = cp.begin(); it != cp.end(); ++it )
        if( *it != word && mystrcmp( *it, word ) == 0 )
            return true;
    return false;
}
bool cmp( char a, char b ) { return tolower( a ) < tolower( b ); }
bool Strcmp( char *a, char *b ) { return strcmp( a, b ) < 0; }

int main()
{
    while( cin >> in && *in != '#' )
    {
        strcpy( ori[ ++i ], in );
        sort( in, in+strlen( in ), cmp );
        str.push_back( strdup( in ) );
    }
    cp = str;
    str.remove_if( Ananagrams );
    str.sort( Strcmp );
    cp.clear();

    for( list<char*>::iterator it = str.begin(); it != str.end(); ++it )
        for( int j = 0; j <= i; ++j )
        {
            strcpy( out, ori[ j ] );
            sort( out, out+strlen( out ), cmp );
            if( !strcmp( out, *it ) )
            {
                cp.push_back( ori[ j ] );
                break;
            }
        }
    cp.sort( Strcmp );
    for( list<char*>::iterator it = cp.begin(); it != cp.end(); ++it )
        cout << *it << endl;

    return 0;
}
