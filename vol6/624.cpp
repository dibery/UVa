#include<cstdio>

int main()
{
    int len, totaltrack;

    while( scanf( "%d", &len ) != EOF )
    {
        scanf( "%d", &totaltrack );
        int track[ totaltrack ], ans = 0, out;
        for( int i = 0; i < totaltrack; ++i )
            scanf( "%d", track+i );
        for( int i = ( 1 << totaltrack )-1, tmp = 0; i && ans != len; --i, tmp = 0 )
        {
            for( int j = 0; j < totaltrack && tmp <= len; ++j )
                if( ( i >> j ) & 1 )
                    tmp += track[ j ];
            if( tmp <= len && tmp > ans )
            {
                ans = tmp;
                out = i;
                if( i == ( 1 << totaltrack ) - 1 )
                    break;
            }
        }
        for( int i = 0; i < totaltrack; ++i )
            if( ( out >> i ) & 1 )
                printf( "%d ", track[ i ] );
        printf( "sum:%d\n", ans );
    }

    return 0;
}
