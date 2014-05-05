#include<cstdio>
#include<algorithm>

int main()
{
    int n;
    char pic[ 12 ][ 26 ];

    while( scanf( "%d\n", &n ) && n )
    {
        int blank[ 12 ] = { 0 }, total = 0, least = 30;
        for( int i = 0; i < n; ++i )
        {
            gets( pic[ i ] );
            for( int k = 0; k < 25; ++k )
                if( pic[ i ][ k ] == ' ' )
                    ++blank[ i ];
            least = std::min( least, blank[ i ] );
            total += blank [ i ];
        }
        printf( "%d\n", total - n*least );
    }

	return 0;
}