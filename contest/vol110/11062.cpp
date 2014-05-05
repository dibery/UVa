#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
bool cmp( char *a, char *b )
{
    return strcmp( a, b ) < 0;
}

int main()
{
    char *word = new char[ 100000 ], *dic[ 501 ] = { NULL }, *tmp = new char[ 100000 ];
    int all = 0, len = 0, status;

    while( status = scanf( "%s", word ) )
    {
        while( word[ strlen( word ) - 1 ] == '-' && getchar() == '\n' )
        {
            scanf( "%s", tmp );
            strcpy( word+strlen( word )-1, tmp );
        }
        for( int i = 0; word[ i ]; ++i )
            word[ i ] = tolower( word[ i ] );
        for( int i = 0; word[ i ]; ++i )
        {
            if( isalpha( word[ i ] ) || word[ i ] == '-' )
                tmp[ len++ ] = word[ i ];
            else
            {
                tmp[ len ] = 0;
                if( *tmp )
                    dic[ all++ ] = strdup( tmp );
                len = 0;
            }
        }
        tmp[ len ] = 0;
        len = 0;
        if( *tmp )
            dic[ all++ ] = strdup( tmp );
        if( status == EOF )
            break;
    }
    std::sort( dic, dic+all, cmp );
    for( int i = 0; i < all; ++i )
        if( i == all-1 || strcmp( dic[ i ], dic[ i+1 ] ) )
            puts( dic[ i ] );

    return 0;
}
