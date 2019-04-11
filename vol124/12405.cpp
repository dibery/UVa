#include<cstdio>

int main()
{
    int test, len;
    char field[ 105 ];
    scanf( "%d", &test );

    for( int i = 1; i <= test; ++i )
    {
        int put = 0;
        scanf( "%d %s", &len, field );
        for( int i = 0; i < len; ++i )
            if( field[ i ] == '.' )
            {
                field[ i ] = field[ i+1 ] = field[ i+2 ] = '#';
                ++put;
            }
        printf( "Case %d: %d\n", i, put );
    }
    return 0;
}
