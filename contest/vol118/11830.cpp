#include<cstdio>

int main()
{
    char dig, val[ 105 ];

    while( scanf( "%c %s\n", &dig, val ) && dig != '0' )
    {
        bool out = false;
        for( int i = 0; val[ i ]; ++i )
            if( val[ i ] != dig && val[ i ] != '0' )
            {
                putchar( val[ i ] );
                out = true;
            }
            else if( val[ i ] == '0' && out )
                putchar( '0' );
        if( !out )
            putchar( '0' );
        puts( "" );
    }

	return 0;
}