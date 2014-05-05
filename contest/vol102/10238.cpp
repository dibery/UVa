#include<cstdio>
#include<cstring>
int assign[ 4001 ][ 51 ][ 90 ];
inline void normal( int *num, int limit )
{
    for( int i = 0; i < limit; ++i )
    {
        num[ i+1 ] += num[ i ] / 10;
        num[ i ] %= 10;
    }
}

int main()
{
    int face, throws, value;

    while( scanf( "%d %d %d\n", &face, &throws, &value ) != EOF )
    {
        int down[ 90 ] = { 1 }, out = 89;
        memset( assign, 0, sizeof( assign ) );
        assign[ 0 ][ 0 ][ 0 ] = 1;
        if( value > ( throws + face * throws ) / 2 )
            value = throws + face * throws - value;
        for( int i = 1; i <= throws; ++i )
        {
            for( int j = 0; j < 86; ++j )
                down[ j ] *= face;
            normal( down, 90 );
        }
        if( value < throws || value > face * throws || !throws )
        {
            putchar( '0' );
            goto end;
        }
        for( int i = 1; i <= value; ++i )
            for( int n = 1; n <= throws; normal( assign[ i ][ n ], 90 ), ++n )
                if( i >= n && i <= face * n )
                    for( int j = 1; j <= face && i >= j; ++j )
                        for( int k = 0; k < 90; ++k )
                            assign[ i ][ n ][ k ] += assign[ i - j ][ n-1 ][ k ];
        for( ; out >= 0 && !assign[ value ][ throws ][ out ]; --out );
        for( ; out >= 0; --out )
            printf( "%d", assign[ value ][ throws ][ out ] );
end:
        putchar( '/' );
        out = 89;
        for( ; !down[ out ]; --out );
        for( ; out >= 0; --out )
            printf( "%d", down[ out ] );
        puts( "" );
    }

    return 0;
}
