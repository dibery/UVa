#include<cstdio>
#include<algorithm>

int main()
{
    int begin, end, h, map[ 10001 ] = { 0 }, i;

    while( scanf( "%d %d %d", &begin, &h, &end ) != EOF )
        for( i = begin; i < end; ++i )
            map[ i ] = std::max( map[ i ], h );
    for( i = 1; i <= 10000; ++i )
        if( map[ i ] != map[ i-1 ] )
        {
            printf( "%d %d", i, map[ i ] );
            ++i;
            break;
        }
    for( ; i <= 10000; ++i )
        if( map[ i ] != map[ i-1 ] )
            printf( " %d %d", i, map[ i ] );
    printf( "\n" );
    return 0;
}
