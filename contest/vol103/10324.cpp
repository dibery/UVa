#include<cstdio>
#include<algorithm>
#include<cstring>
char in[ 1000001 ];
int a, b, t = 0, test, data[ 1000001 ];

int main()
{
    while( gets( in ) && *in )
    {
        scanf( "%d\n", &test );
        printf( "Case %d:\n", ++t );
        memset( data, 0, sizeof( data ) );
        if( *in == '1' )
            ++data[ 0 ];
        for( int i = 1; in[ i ]; ++i )
            data[ i ] = data[ i-1 ] + in[ i ] - '0';
        while( test-- )
        {
            scanf( "%d %d\n", &a, &b );
            if( a > b )
                std::swap( a, b );
            puts( data[ b ] - data[ a? a-1 : a ] == 0 && in[ a ] == '0' || in[ a ] == '1' && data[ b ] - data[ a? a-1 : a ] == ( b - (a? a-1 : a) ) ? "Yes" : "No" );
        }
    }

    return 0;
}
