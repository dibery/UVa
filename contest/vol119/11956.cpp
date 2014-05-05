#include<cstdio>

int main()
{
    int t;
    char str[ 100000 ];
    scanf( "%d\n", &t );

    for( int i = 1; i <= t; ++i )
    {
        unsigned char val[ 100000 ] = { 0 }, *ptr = val;
        gets( str );
        printf( "Case %d:", i );
        for( int k = 0; str[ k ]; ++k )
            if( str[ k ] == '>' )
                ptr = ptr == val+99? val : ptr+1;
            else if( str[ k ] == '<' )
                ptr = ptr == val? val+99 : ptr-1;
            else if( str[ k ] == '+' )
                ++*ptr;
            else if( str[ k ] == '-' )
                --*ptr;
        for( int i = 0; i < 100; ++i )
            printf( " %02X", val[ i ] );
        puts( "" );
    }

	return 0;
}