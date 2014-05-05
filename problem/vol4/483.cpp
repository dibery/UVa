#include<cstdio>
#include<cstring>

int main()
{
    char word[ 100 ], end;

    while( scanf( "%s%c", word, &end ) != EOF )
    {
        for( int i = strlen( word )-1; i >= 0; --i )
            putchar( word[ i ] );
        putchar( end );
    }
    return 0;
}
