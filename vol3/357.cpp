#include<cstdio>
long long int sol[ 30001 ][ 6 ] = { 0 };

int main()
{
    int money, val[] = { 0, 1, 5, 10, 25, 50 };
    for( int i = 0; i <= 30000; ++i )
        for( int j = 0; j <= 5; ++j )
            sol[ i ][ j ] = 0;
    for( int i = 0; i <= 5; ++i )
        sol[ 0 ][ i ] = 1;
    for( int i = 1; i <= 30000; ++i )
        for( int j = 1; j <= 5; ++j )
                sol[ i ][ j ] = val[ j ] > i ? sol[ i ][ j-1 ] : sol[ i ][ j-1 ] + sol[ i-val[ j ] ][ j ];

    while( scanf( "%d", &money ) != EOF )
        if( sol[ money ][ 5 ] == 1 )
            printf( "There is only 1 way to produce %d cents change.\n", money );
        else
            printf( "There are %lld ways to produce %d cents change.\n", sol[ money ][ 5 ], money );
    return 0;
}
