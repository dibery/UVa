#include<cstdio>
#include<cstring>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
bool isPand( char* begin, char* end )
{
    char cmp[ 81 ] = { 0 };
    ++end;
    reverse_copy( begin, end, cmp );
    return !strncmp( cmp, begin, end - begin );
}

int main()
{
    char str[ 81 ];

    while( gets( str ) )
    {
        int ans = 0;
        set<string> dict;
        for( int i = 0; str[ i ]; ++i )
            for( int j = i; str[ j ]; ++j )
                if( isPand( str+i, str+j ) && dict.find( string( str+i, j-i+1 ) ) == dict.end() )
                    ++ans, dict.insert( string( str+i, j-i+1 ) );
        printf( "The string '%s' contains %d palindromes.\n", str, ans );
    }
}
