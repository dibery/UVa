#include<cstdio>

int main()
{
    int t, line;
    char str[ 501 ] = { 0 };
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d", &line );
        getchar();
        printf( "Case %d:\n", i );
        for( int k = 0; k < line; ++k )
        {
            gets( str );
            for( int n = 0; str[ n ]; ++n )
                if( !n || str[ n-1 ] != ' ' || str[ n ] != ' ' )
                    putchar( str[ n ] );
            puts( "" );
        }
        if( i != t )
            puts( "" );
    }

	return 0;
}