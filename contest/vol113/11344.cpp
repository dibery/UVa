#include<cstdio>

int main()
{
    int t, size, modulus[ 12 ];
    char num[ 1001 ];
    scanf( "%d", &t );

    while( t-- )
    {
        bool great = true;
        scanf( "%s %d", num, &size );
        for( int i = 0; i < size; ++i )
            scanf( "%d", modulus+i );
        for( int i = 0, mod = 0; i < size && great; ++i, mod = 0 )
        {
            for( int k = 0; num[ k ]; ++k )
                mod = ( 10 * mod + num[ k ] - '0' ) % modulus[ i ];
            if( mod )
                great = false;
        }
        printf( "%s - %s.\n", num, great? "Wonderful" : "Simple" );
    }

    return 0;
}
