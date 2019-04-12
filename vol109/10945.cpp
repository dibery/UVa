#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
bool Pand( char *str )
{
    char *tmp = strdup( str );
    reverse( tmp, tmp+strlen( tmp ) );
    return strcmp( tmp, str ) == 0;
}

int main()
{
    char str[ 10000 ], cp[ 10000 ];

    while( gets( str ) && strcmp( str, "DONE" ) )
    {
        int i = -1, len = strlen( str );
        for( int j = 0; j < len; ++j )
            if( isalpha( str[ j ] ) )
                cp[ ++i ] = tolower( str[ j ] );
        cp[ ++i ] = 0;
        if( Pand( cp ) )
            puts( "You won't be eaten!" );
        else
            puts( "Uh oh.." );
    }

	return 0;
}