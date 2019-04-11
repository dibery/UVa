#include<cstdio>
const char on = '1', off = '0';

int main()
{
    int h, w;

    while( scanf( "%d %d\n", &h, &w ) == 2 )
    {
        char field[ h ][ w+1 ];
        int ans = 0;
        for( int i = 0; i < h; ++i )
            gets( field[ i ] );
        for( int i = 0; i < h; ++i )
            for( int j = 0; j < w; ++j )
                if( field[ i ][ j ] == on )
                {
                    int len = w;
                    for( int m = i; m < h; ++m )
                        for( int n = j; n < len; ++n )
                            if( field[ m ][ n ] == on )
                                ++ans;
                            else
                            {
                                len = n;
                                break;
                            }
                }
        printf( "%d\n", ans );
    }
    return 0;
}
