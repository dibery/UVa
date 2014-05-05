#include<cstdio>
int fib[ 4668 ][ 1001 ] = { { 0 }, { 1 }, { 1 } }, n;

int main()
{
    for( int i = 3; i < 4668; ++i )
    {
        for( int j = 0; j < 1000; ++j )
            fib[ i ][ j ] += fib[ i-1 ][ j ] + fib[ i-2 ][ j ];
        for( int j = 0; j < 1000; ++j )
        {
            fib[ i ][ j+1 ] += fib[ i ][ j ] / 10;
            fib[ i ][ j ] %= 10;
        }
    }
    while( scanf( "%d", &n ) != EOF )
    {
        int out = 1000;
        while( !fib[ n ][ --out ] );
        while( out >= 0 )
            printf( "%d", fib[ n ][ out-- ] );
        puts( "" );
    }

    return 0;
}
