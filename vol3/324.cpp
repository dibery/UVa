#include<cstdio>
int fact[ 367 ][ 1200 ] = { 1 }, ans[ 367 ][ 10 ] = { 0, 1 };

int main()
{
    int in;

    for( int i = 1, k = 1199; i <= 366; ++i, k = 1199 )
    {
        for( int j = 0; j < 1200; ++j )
            if( fact[ i-1 ][ j ] )
                fact[ i ][ j ] = fact[ i-1 ][ j ] * i;
        for( int j = 0; j < 1200; ++j )
            if( fact[ i ][ j ] > 9 )
            {
                fact[ i ][ j+1 ] += fact[ i ][ j ] / 10;
                fact[ i ][ j ] %= 10;
            }
        while( !fact[ i ][ k ] )
            --k;
        for( ; k >= 0; --k )
            ++ans[ i ][ fact[ i ][ k ] ];
    }
    while( scanf( "%d", &in ) && in )
    {
        printf( "%d! --\n", in );
        for( int i = 0; i < 5; ++i )
            printf( "    (%d)    %d", i, ans[ in ][ i ] );
        puts( "" );
        for( int i = 5; i < 10; ++i )
            printf( "    (%d)    %d", i, ans[ in ][ i ] );
        puts( "" );
    }
    return 0;
}
