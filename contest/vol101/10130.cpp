#include<cstdio>
#include<algorithm>

int main()
{
    int t, item, man, value[ 1001 ], cost[ 1001 ], carry;

    for( scanf( "%d", &t ); t--; )
    {
        int ans = 0, all = 0, pack[ 1001 ][ 31 ] = { 0 };
        scanf( "%d", &item );
        for( int i = 1; i <= item; ++i )
            scanf( "%d %d", value+i, cost+i ), all += cost[ i ];
        for( int i = 1; i <= item; ++i )
            for( int j = 0; j <= 30; ++j )
                if( j >= cost[ i ] )
                    pack[ i ][ j ] = std::max( pack[ i-1 ][ j - cost[ i ] ] + value[ i ], pack[ i-1 ][ j ] );
                else
                    pack[ i ][ j ] = pack[ i-1 ][ j ];
        scanf( "%d", &man );
        for( int i = 0; i < man; ++i )
            scanf( "%d", &carry ), ans += pack[ item ][ carry ];
        printf( "%d\n", ans );
    }
}
