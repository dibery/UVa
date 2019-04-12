#include<cstdio>
#include<cstring>

int main()
{
    char string[ 101 ], map[ 26 ], tmp, from, to;
    int cmd, begin, t = 0;

    while( scanf( "%s ", string ) != EOF )
    {
        printf( "Case #%d: The encoding string is ", ++t );
        int out = 0, len = strlen( string );
        for( int i = 0; i < 26; ++i )
            scanf( "%c ", map+i );
        scanf( "%d", &cmd );
        for( int i = 0; i < cmd; ++i )
        {
            scanf( "%d %c %c ", &begin, &from, &to );
            while( out < begin )
                putchar( map[ string[ out++ ]-'a' ] );
            map[ from-'a' ] = to;
        }
        while( out < len )
            putchar( map[ string[ out++ ]-'a' ] );
        puts( ".\n" );
    }

    return 0;
}