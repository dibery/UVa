#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
bool cmp( char a, char b )
{
    if( tolower( a ) != tolower( b ) )
        return tolower( a ) < tolower( b );
    else
        return a < b;
}

int main()
{
    char word[ 100 ];
    int len;
    gets( word );

    while( gets( word ) != NULL )
    {
        len = strlen( word );
        std::sort( word, word+len, cmp );
        do
            puts( word );
        while( std::next_permutation( word, word+len, cmp ) );
    }

    return 0;
}
