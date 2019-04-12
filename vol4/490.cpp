#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
    char out[ 100 ][ 101 ], in[ 100 ][ 101 ];
    int i = 0, max = 0;
    memset( out, 0, sizeof( out ) );
    memset( in, 0, sizeof( in ) );

    while( gets( in[ i ] ) )
        max = std::max( max, (int)strlen( in[ i++ ] ) );
    for( int k = i-1; k >= 0; --k )
        for( int l = 0; l < max; ++l )
            out[ l ][ i - k - 1 ] = in[ k ][ l ]? in[ k ][ l ] : ' ';
    for( int k = 0; k < max; ++k )
        puts( out[ k ] );

	return 0;
}