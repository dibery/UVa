#include<cstdio>
#include<algorithm>
const int MAX = 123456789;

int main()
{
    int test, size, coin[ 100 ], package[ 20001 ], target;
    scanf( "%d", &test );

    while( test-- )
    {
        for( int i = 1; i <= 20000; ++i )
            package[ i ] = MAX;
        *package = 0;
        scanf( "%d %d", &target, &size );
        for( int i = 0; i < size; ++i )
            scanf( "%d", coin+i );
        for( int i = 0; i < size; ++i )
            for( int j = 20000; j >= 0; --j )
                if( package[ j ] != MAX && j + coin[ i ] <= 20000 )
                    package[ j + coin[ i ] ] = std::min( package[ j + coin[ i ] ], package[ j ] + 1 );
        for( size = target; package[ size ] == MAX; ++size );
        printf( "%d %d\n", size, package[ size ] );
    }
    return 0;
}
