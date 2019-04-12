#include<cstdio>
#include<cstdlib>
#include<cmath>
const char chr[] = { "0123456789ABCDEF" };

int main()
{
    char str[ 1000 ];
    int in, out, real;

    while( scanf( "%s %d %d", str, &in, &out ) != EOF )
    {
        int i = -1;
        char print[ 8 ] = { 0 };

        real = strtol( str, NULL, in );
        if( real >= pow( out, 7.0 ) )
        {
            puts( "  ERROR" );
            continue;
        }
        if( !real )
        {
            printf( "%7d\n", 0 );
            continue;
        }
        while( real )
        {
            print[ ++i ] = real % out;
            real /= out;
        }
        for( int k = 6 - i; k; --k )
            putchar( ' ' );
        for( ; i >= 0; --i )
            printf( "%c", chr[ print[ i ] ] );
        puts( "" );
    }
    return 0;
}
