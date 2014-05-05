#include<cstdio>

int main()
{
    int n, ans[ 101 ][ 26 ] = { 0 }, prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    for( int i = 2; i <= 100; ++i )
    {
        int tmp = i;
        for( int j = 0; j < 26; ++j )
            ans[ i ][ j ] = ans[ i-1 ][ j ];
        for( int j = 0; tmp != 1; ++j )
            while( tmp % prime[ j ] == 0 )
        {
            tmp /= prime[ j ];
            ++ans[ i ][ j ];
        }
    }

    while( scanf( "%d", &n ) && n )
    {
        int tmp;
        for( tmp = 25; ans[ n ][ tmp ] == 0; --tmp );
        printf( "%3d! =", n );
        if( tmp < 15 )
            for( int i = 0; i <= tmp; ++i )
                printf( "%3d%s", ans[ n ][ i ], i == tmp? "\n" : "" );
        else
        {
            for( int i = 0; i < 15; ++i )
                printf( "%3d%s", ans[ n ][ i ], i == 14? "\n" : "" );
            printf( "      " );
            for( int i = 15; i <= tmp; ++i )
                printf( "%3d%s", ans[ n ][ i ], i == tmp? "\n" : "" );
        }
    }

    return 0;
}
