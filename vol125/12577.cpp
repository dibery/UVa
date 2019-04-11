#include<cstdio>

int main()
{
    char word[ 10 ];
    int t = 0;

    while( scanf( "%s", word ) != EOF )
        if( *word == 'H' )
            printf( "Case %d: Hajj-e-Akbar\n", ++t );
        else if( *word == 'U' )
            printf( "Case %d: Hajj-e-Asghar\n", ++t );
    return 0;
}
