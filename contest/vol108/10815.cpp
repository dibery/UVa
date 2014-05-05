#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
bool cmp( char *a, char *b ) { return strcmp( a, b ) < 0; }

int main()
{
    char word[ 5201 ] = { 0 }, *dic[ 500001 ] = { NULL }, tmp;
    int all = 0, len = 0;

    while( scanf( "%c", &tmp ) != EOF )
        if( isalpha( tmp ) )
            word[ len++ ] = tolower( tmp );
        else if( len )
        {
            word[ len ] = 0;
            dic[ all++ ] = strdup( word );
            len = 0;
        }
    if( isalpha( tmp ) )
    {
        word[ len ] = 0;
        dic[ all++ ] = strdup( word );
    }
    std::sort( dic, dic+all, cmp );
    for( int i = 0; i < all; ++i )
        if( i == all-1 || strcmp( dic[ i ], dic[ i+1 ] ) )
            puts( dic[ i ] );

	return 0;
}